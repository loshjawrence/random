#pragma once

#include <condition_variable>
#include <mutex>
#include <algorithm>

namespace AysncContainer
{
    // Alloc some scratch buffers, as thread need them they can 'take a number', or wait till one is available
    struct ScratchBufferInfo
    {
        uint64_t scratchBufferIndex = 0;
        char* scratchBuffer = nullptr;
    };

    class ScratchBuffersAsync
    {
    public:
        uint64_t m_entries;
        char** m_scratchBuffers;    // An array[m_entries] of char[m_entryLength], 
        uint64_t* m_tokenStack;     // Threads push/pop a scratchBuffers index number off of this to get/make available an index in the buffer
        uint64_t m_tokenStackIndex; // Stack Index, push/pops move this up and down the fixed sized stack array to get/make available indicies into the m_scratchBuffers array
        uint64_t m_entryLength;     // fixed size byte length of each entry that m_scratchBuffers points to, determined on construction
        std::mutex m_mutex;
        std::condition_variable m_condition;

        ScratchBuffersAsync(const uint64_t maxMemoryUsage, const uint64_t entries, const uint64_t entryLength)
            :
            m_entries(std::min(entries, maxMemoryUsage / entryLength)),
            m_scratchBuffers(new char*[m_entries]),
            m_tokenStack(new uint64_t[m_entries + 1]),  // m_tokenStackIndex 0 will indicate empty stack
            m_tokenStackIndex(m_entries),               // Start at the top of the stack since all entries will be available at the start
            m_entryLength(entryLength)
        {
            m_tokenStack[0] = 0;
            for (uint64_t i = 0; i < m_entries; ++i)
            {
                m_scratchBuffers[i] = new char[m_entryLength];
                m_tokenStack[i + 1] = i;
            }
        }

        ~ScratchBuffersAsync()
        {
            if (m_tokenStack != nullptr)
            {
                delete[] m_tokenStack;
                m_tokenStack = nullptr;
            }

            for (uint64_t i = 0; i < m_entries; ++i)
            {
                if (m_scratchBuffers[i] != nullptr)
                {
                    delete[] m_scratchBuffers[i];
                    m_scratchBuffers[i] = nullptr;
                }
            }

            if (m_scratchBuffers != nullptr)
            {
                delete[] m_scratchBuffers;
                m_scratchBuffers = nullptr;
            }
        }

        void free()
        {
            this->~ScratchBuffersAsync();
            m_entries = 0;
            m_tokenStackIndex = 0;
            m_entryLength = 0;
        }

        char* operator[](const uint64_t index) const 
        {
            // Get the start addr of a buffer in m_scratchBuffers
            return m_scratchBuffers[index];
        }

        uint64_t pop() {
            // Pop available buffer indices off the stack
            std::unique_lock<std::mutex> lock(m_mutex);
            m_condition.wait(lock, [&] {return m_tokenStackIndex != 0; }); // A thread atomically releases the mutex waits here if the condition returns false (m_tokenStackIndex == 0, out of tokens). It will wake up if it recieves a notify_* from another thread and try the condition again, and try to obtain the lock if it succeeds, otherwise go back to sleep
            uint64_t scratchBuffersIndex = m_tokenStack[m_tokenStackIndex];
            m_tokenStackIndex--;
            lock.unlock();
            m_condition.notify_one();
            return scratchBuffersIndex;
        }

        void push(const uint64_t token) {
            // Push available buffer indices back onto the stack when a thread is finished with it
            {
                std::lock_guard<std::mutex> lock(m_mutex);
                m_tokenStackIndex++;
                m_tokenStack[m_tokenStackIndex] = token;
            }
            m_condition.notify_one();
        }

        ScratchBuffersAsync() = delete;                                      // Disable default ctor
        ScratchBuffersAsync(const ScratchBuffersAsync&) = delete;            // Disable copy ctor
        ScratchBuffersAsync& operator=(const ScratchBuffersAsync&) = delete; // Disable assignment
    };
}
