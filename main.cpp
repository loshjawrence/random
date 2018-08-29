#include <vector>
#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <chrono>
#include <thread>
//#include <memory>
//#include <experimental/filesystem>
//namespace fs = std::experimental::filesystem;

//#include <windows.h>
//#include <tchar.h>
//#include <stdio.h>
//#include <stdlib.h>             // For exit
//#include <io.h>
//#include <fcntl.h>
//#include <cstdio>


struct mychar {
    mychar() {};
    char data;
};


int main()
{
    uint64_t size = 1 * 1207959552; // bytesToRead from PointClouds, 1.2B
    uint64_t entries = 6;

    auto start = std::chrono::system_clock::now();

    // windows perf monitor only shows increase in heap memory when it gets written to (new char[garrillion] wont show anything until you touch it)
    {
        
        //std::vector<mychar> charvec1(size); // gets the mem and no init since init is a no-op
        //std::vector<char> charvec1(size); // gets the mem and inits 0.6 sec
    //uint8_t* chararray = new uint8_t[size]; // same as malloc timing, built-in types init to garbage
    //uint8_t* chararray = (uint8_t*)malloc(size*sizeof(uint8_t)); // same as new timing


        //some other test
        //char** arrayarray;
        //char* stack;
        //arrayarray = new char*[entries];
        //stack = new char[entries+1];
        //for (uint64_t i = 0; i < entries; ++i)
        //{
        //    arrayarray[i]  = new char[size];
        //    stack[i+1] = i;
        //}

        // 0.01 sec
        //char* chararray = new char[size]; 
        //std::unique_ptr<char> wrap(chararray); //this will not perform value-init, destruct when leaving scope(just as fast as normal delete[] chararray), unless ownership transfered with return std::move(wrap)

        //auto chararry = std::make_unique<char[]>(size); // this will perform value-init
    }

    auto end = std::chrono::system_clock::now();
    std::cout << "\nElapsed Time(s): " << std::chrono::duration<double>(end-start).count() << "\n";
    ////std::vector<int> charvec1; // just declares 0 sized vec
    ////charvec1.reserve(size); // reserve just gets the mem does not init
    ////charvec1.resize(size); // sets size and gets the mem if it doesnt already have it and then inits
    //std::vector<myint> charvec1(size); // gets the mem and no init since our default ctor doesnt do anything
    //std::vector<myint> charvec1; // just declares 0 sized vec
    //charvec1.reserve(size); // reserve just gets the mem does not init
    //charvec1.resize(size); // sets size and gets the mem if it doesnt already have, no init since default ctor doesnt do anything
    //uint8_t* chararray = new uint8_t[size]; // same as malloc, This seems to init to 0? just chance?
    //uint8_t* chararray = (uint8_t*)malloc(size*sizeof(uint8_t)); //same as new, inits to 0? just chance?

    //for (int i = 0; i < size; ++i) {
    // std::endl doesn't seem slower than \n
        //std::cout << "elem: " << chararray[i] << std::endl;
        //std::cout << "\nelem: " << charvec1[i].data;
        //std::cout << "\nelem: " << charvec1[i];
    //}
}

//int main()
//{
    ////char* chararray = nullptr;
    ////chararray = new char[100000];
    //uint64_t sevenB = 7000000000;
    //const uint64_t sevenM = 7000000;
    ////char* chararray = new char[sevenM*100];

    ////std::array<char, sevenM> myarray = {};
    //std::vector<char> myarray;
    //myarray.reserve(sevenB);
    //std::cout << "\n capacity: " << myarray.capacity() << ", size: " << myarray.size();
    ////for (auto& item : myarray) { std::cout << "\n" << item; }

    ////if (chararray == nullptr) { std::cout << "\nca STILL NULLPTR"; } else { std::cout << "\nca NO LONGER NULLPTR"; }
    //if (myarray.data() == nullptr) { std::cout << "\nca STILL NULLPTR"; } else { std::cout << "\nca NO LONGER NULLPTR"; }
    //                    using namespace std::chrono_literals;
    //                    std::this_thread::sleep_for(30s);



    // MATH LOOP
    //auto start = std::chrono::system_clock::now();
    //double result = 0.01f;
    //for (uint64_t i = 1; i < 400000000; i++)
    //{
    //    result += i;
    //}
    //auto stop = std::chrono::system_clock::now();
    //std::cout << "\nElapsed Time(s): " << std::chrono::duration<double>(stop-start).count() << "\n";
//}


// redirect stdout
//int main()
//{
//	const bool redirect = true;
//    // !context.verbose() means only print messages when finished, these are needed for std::cout redirection
//    std::stringstream redirectBuffer; // This can be an ofstream as well or any other ostream
//    std::streambuf* coutsBuffer = nullptr;
//    if (redirect)
//    {
//        //coutsBuffer = std::cout.rdbuf();         // Save cout's buffer 
//        //std::cout.rdbuf(redirectBuffer.rdbuf()); // Redirect cout to our stringstream buffer (or any other ostream derivative)
//        coutsBuffer = std::cout.rdbuf(redirectBuffer.rdbuf()); // Redirect cout to our stringstream buffer (or any other ostream derivative) and put the buffer thats getting replaced (std::couts original buffer) into coutsBuffer
//        //... Use cout as usual and messages passed to it will get fed into redirectBuffer
//    }
//	
//	std::cout << "\nTESTING\n";
//
//	using namespace std::chrono_literals;
//	std::this_thread::sleep_for(2s);
//
//
//    if (redirect)
//    {
//        const std::string redirectBufferString(redirectBuffer.str()); // Save what was sent to our buffer
//        std::cout.rdbuf(coutsBuffer);                                 // When done, redirect cout to its old self
//        std::cout << redirectBuffer.str();                            // Print what was genrated during processing
//    }
//}



//// THIS IS FOR FILE GLOBBING
//  ../path/*.txt  will grab all txt in path dir
//  ../path/*/*.txt  will recursively grab all txt in path and its subdirs
//  ../path/begin*end.txt  will grab all txt that begin and end with begin and end
//  ../path/*.t*  will grab all files that end with t in path dir
//namespace fs = std::experimental::filesystem;
//namespace po = boost::program_options;
//
//void replace_all(std::wstring& source, const wchar_t replace, const std::wstring& replacement)
//{
//    size_t pos = 0 ;
//    while (pos < source.length() && std::wstring::npos != (pos = source.find(replace, pos)))
//    {
//        source.replace(pos, 1, replacement);
//        pos += replacement.length();
//    }
//}
//
//std::wstring to_regex_expression(const std::wstring& filename)
//{
//    std::wstring expression(filename) ;
//
//    replace_all(expression, L'.', L"\\.") ;
//    replace_all(expression, L'*', L".*") ;
//
//    return expression ;
//}
//
//std::vector<fs::path> globPaths(std::vector<std::wstring>& patterns, const std::wstring& extensions = L".*")
//{
//    std::vector<fs::path> results;
//    for (auto& pattern : patterns)
//    {
//        fs::path pathPattern(pattern);
//        if (std::wstring::npos == pattern.find_first_of(L"*"))
//        {
//            if (fs::exists(pathPattern))
//            {
//                results.push_back(std::move(pathPattern));
//                continue;
//            }
//        }
//
//        std::wregex expr(to_regex_expression(pathPattern.filename().wstring()), std::regex_constants::icase);
//        fs::path parentPath = pathPattern.parent_path();
//
//        bool recursive = parentPath.wstring().find_first_of(L"*") != std::wstring::npos ? true : false;
//
//        if (recursive)
//        {
//            // Remove the stars
//            std::wstring string = parentPath.wstring();
//            string.erase(string.find_first_of(L"*"), string.size() - 1);
//
//            for (fs::path p : fs::recursive_directory_iterator(fs::canonical(fs::path(string))))
//            {
//                // Skip if not a file
//                if (fs::is_directory(p)) continue;
//
//                // Skip if no match
//                if (!std::regex_match(p.filename().wstring(), expr)) continue;
//
//                // Skip if no a file extension we care about (useful for ../path/*/*)
//                if (!std::regex_match(p.filename().extension().wstring(), std::wregex(extensions, std::regex_constants::icase))) continue;
//
//                results.push_back(std::move(p));
//            }
//        }
//        else
//        {
//            parentPath = fs::canonical(parentPath);
//            for (fs::path p : fs::directory_iterator(parentPath))
//            {
//                // Skip if not a file
//                if (fs::is_directory(p)) continue;
//
//                // Skip if no match
//                if (!std::regex_match(p.filename().wstring(), expr)) continue;
//
//                // Skip if no a file extension we care about (useful for ../path/*/*)
//                if (!std::regex_match(p.filename().extension().wstring(), std::wregex(extensions, std::regex_constants::icase))) continue;
//
//                results.push_back(std::move(p));
//            }
//        }
//    }
//    return results;
//}
//


// THIS IS FOR SEARCHING FOR A DIRECTORY prob need to adjust the two logic things in the for loop
//#include <experimental\filesystem>
//namespace fs = std::experimental::filesystem;
//fs::path findDirectory(const std::string directoryOfInterest)
//{
//    fs::path currentDirectory = fs::current_path();
//    // Check up the tree first
//    while (currentDirectory.stem().generic_string() != directoryOfInterest && !currentDirectory.empty())
//    {
//        currentDirectory = currentDirectory.parent_path();
//    }
//
//    // Check if we found it
//    if (currentDirectory.stem().generic_string() == directoryOfInterest)
//    {
//        return currentDirectory;
//    }
//    else
//    {
//        // Start over looking down the tree, stopping after maxSearchDepth
//        currentDirectory = fs::current_path();
//        using fsrdi = fs::recursive_directory_iterator;
//        for (auto p = fsrdi(currentDirectory); p != fsrdi(); ++p)
//        {
//            if (p->path().filename() != directoryOfInterest)
//            {
//                p.pop();
//                continue;
//            }
//
//            if (fs::is_directory(p->path()) && p->path().stem().generic_string() == directoryOfInterest)
//            {
//                return *p;
//            }
//        }
//    }
//    std::cout << "\nCouldn't find the '" << directoryOfInterest << "' directory from " << currentDirectory;
//    return fs::current_path();
//}
//
//static const std::string exePath = findDirectory("build").append("Data").generic_string();


//#define PAGELIMIT 80            // Number of pages to ask for
//
//LPTSTR lpNxtPage;               // Address of the next page to ask for
//DWORD dwPages = 0;              // Count of pages gotten so far
//DWORD dwPageSize;               // Page size on this computer
//
//INT PageFaultExceptionFilter(DWORD dwCode)
//{
//    LPVOID lpvResult;
//
//    // If the exception is not a page fault, exit.
//
//    if (dwCode != EXCEPTION_ACCESS_VIOLATION)
//    {
//        _tprintf(TEXT("Exception code = %d.\n"), dwCode);
//        return EXCEPTION_EXECUTE_HANDLER;
//    }
//
//    _tprintf(TEXT("Exception is a page fault.\n"));
//
//    // If the reserved pages are used up, exit.
//
//    if (dwPages >= PAGELIMIT)
//    {
//        _tprintf(TEXT("Exception: out of pages.\n"));
//        return EXCEPTION_EXECUTE_HANDLER;
//    }
//
//    // Otherwise, commit another page.
//
//    lpvResult = VirtualAlloc(
//                     (LPVOID) lpNxtPage, // Next page to commit
//                     dwPageSize,         // Page size, in bytes
//                     MEM_COMMIT,         // Allocate a committed page
//                     PAGE_READWRITE);    // Read/write access
//    if (lpvResult == NULL )
//    {
//        _tprintf(TEXT("VirtualAlloc failed.\n"));
//        return EXCEPTION_EXECUTE_HANDLER;
//    }
//    else
//    {
//        _tprintf(TEXT("Allocating another page.\n"));
//    }
//
//    // Increment the page count, and advance lpNxtPage to the next page.
//
//    dwPages++;
//    lpNxtPage = (LPTSTR) ((PCHAR) lpNxtPage + dwPageSize);
//
//    // Continue execution where the page fault occurred.
//
//    return EXCEPTION_CONTINUE_EXECUTION;
//}
//
//VOID ErrorExit(LPTSTR lpMsg)
//{
//    _tprintf(TEXT("Error! %s with error code of %ld.\n"),
//             lpMsg, GetLastError ());
//    exit (0);
//}
//
//
//
//int main()
//{
//
//    // OS file reading writing not using buffering/caching
//    // See Roy Longbottom's answer with Windows and Linux code
//    // https://stackoverflow.com/questions/25899806/is-there-a-way-not-to-use-cache-in-c 
//
//    fs::path filename("C:\\Users\\jlawrence\\DATASETS\\Point Clouds\\test.txt");
//    //std::fstream filestream;
//    //filestream.open(filename);
//    //filestream << std::string("more lorem ipsum");
//
//    uint32_t osNoBuffering = FILE_FLAG_NO_BUFFERING & 0; // 0 to disable this flag, ~0 to enable this flag, Turning it on will make cold reads faster(typical case), Turning it off will allow the OS to use the system file cache (used by the os to make repeated reads faster)
//
//    // VirtualAlloc
//    // example at bottom https://docs.microsoft.com/en-us/windows/desktop/Memory/reserving-and-committing-memory 
//    // https://msdn.microsoft.com/library/windows/desktop/aa366887
//
//    // CreateFile
//    // https://docs.microsoft.com/en-us/windows/desktop/api/FileAPI/nf-fileapi-createfilea
//
//    // FIle IO buffering
//    // https://docs.microsoft.com/en-us/windows/desktop/FileIO/file-buffering
//    // See answer about Windows calls (non-blocking IO calls, the ReadFileScatter is probably useless but WriteFileGather might be useful later)
//    // https://stackoverflow.com/questions/13421767/multithread-read-from-disk
//
//
//    // THIS IS A FAILED ATTEMPT TO CREATE A DRIVE LABEL, DOCS ARE UNCLEAR HOW TO DO THIS GIVEN A DRIVE LETTER
//    // THE REASON THIS WAS ATTEMPTED WAS TO EVENTUALLY GET THE DRIVE TYPE(SSD/HDD) AND SECTOR SIZE
//    // SECTOR SIZE CAN JUST BE SET TO 4K TO WORK WITH EVERYTHING AND STILL HAVE GOOD PERFORMANCE(OR BETTER)
//    // DRIVE TYPE, IF I CAN'T DEDUCE IT BY OTHER MEANS, CAN BE LEFT UP TO THE USER, i.e. HOPE THEY DON'T HAVE A MIX OF DRIVES AND SET THE PROPER IO CONCURRENCY TO 1 WHEN HDD
////    //https://docs.microsoft.com/en-us/windows/desktop/api/WinBase/nf-winbase-setvolumelabela 
////    //https://docs.microsoft.com/en-us/windows/desktop/FileIO/naming-a-volume
////    // limit to 11 chars
////    //wchar_t* driveLabel = L"C:DRVLBL";
////    //bool bSetVolumeLabelResult = SetVolumeLabelW(
////    //                                  filename.root_name().wstring().c_str(),
////    //                                  driveLabel
////    //                              );
////    char* driveLabel = "C:Label";
////    bool bSetVolumeLabelResult = SetVolumeLabelA(
////                                                    filename.root_name().string().append("\\").c_str(),
////                                                    driveLabel
////                                                );
//////#define wszDrive L"\\\\.\\PhysicalDrive0"
////    //CreateFile should auto select between the ascii(A) and unicode(W) versions
////    // https://msdn.microsoft.com/en-us/library/windows/desktop/aa363216(v=vs.85).aspx
////    HANDLE hDrive = CreateFile(  //TODO: comment on what each of these does
////                            filename.root_name().string().c_str(),
////                            0,
////                            FILE_SHARE_READ | FILE_SHARE_WRITE,
////                            NULL, OPEN_EXISTING, 
////                            0,
////                            NULL
////                         );
////
////    if (hDrive == INVALID_HANDLE_VALUE)
////    {
////        std::cout << "\nCreateFile for hDrive failed, error: " << GetLastError();
////        return 1;
////    }
//
//    //if (osNoBuffering)
//    //{
//        // FILE_FLAG_NO_BUFFERING requires that we, the app, provide the OS a sector aligned buffer.
//        // This just means we ask the OS what the device's sector size is and round up our bytesToRead
//
//        //DISK_GEOMETRY pdg = { 0 };
//        //BOOL result = DeviceIoControl(
//        //                                hDrive,
//        //                                IOCTL_DISK_GET_DRIVE_GEOMETRY,
//        //                                (LPVOID)NULL, 0,
//        //                                &pdg, sizeof(pdg),
//        //                                (LPDWORD)NULL,
//        //                                (LPOVERLAPPED)NULL // TODO: look into this arg for async IO
//        //                             );
//        //if (!result)
//        //{
//        //    std::cout << "\nDeviceIoControl failed, error: " << GetLastError();
//        //    std::cout << "\nTurning buffering back on..";
//        //    osNoBuffering = 0;
//        //}
//        //else 
//        //{
//        //    std::cout << "\nSector size: " << pdg.BytesPerSector;
//        //    bytesToRead += pdg.BytesPerSector - (bytesToRead % pdg.BytesPerSector); // Top it off
//        //}
//
//        // CAN SIMPLY SET THIS TO 4K
//    //}
//
//    HANDLE hFile = CreateFileW(  //TODO: comment on what each of these does
//                            filename.wstring().c_str(), // Preserve wchar_t
//                            GENERIC_READ,// | GENERIC_WRITE,
//                            FILE_SHARE_READ,// | FILE_SHARE_WRITE,
//                            NULL, OPEN_EXISTING, // CREATE_ALWAYS
//                            FILE_ATTRIBUTE_READONLY | FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_NO_BUFFERING,  //FILE_FLAG_RANDOM_ACCESS FILE_FLAG_WRITE_THROUGH FILE_FLAG_OVERLAPPED 
//                            NULL
//                         );
//    if (hFile == INVALID_HANDLE_VALUE)
//    {
//        std::cout << "\nCreateFile for hFile failed, error: " << GetLastError();
//        return 1;
//    }
//
//    int fd = _open_osfhandle((intptr_t)hFile, _O_RDONLY);
//
//    if (fd == -1)
//    {
//        CloseHandle(hFile);
//        std::cout << "\n_open_osfhandle failed, error: " << GetLastError();
//        return 1;
//    }
//
//    FILE* f = _fdopen(fd, "r"); // open file, writes appending after
//
//    if (f == 0)
//    {
//        _close(fd); // Also calls CloseHandle()
//        std::cout << "\n_fdopen failed, error: " << GetLastError();
//        return 1;
//    }
//
//
//    HANDLE hFile2 = CreateFileW(  //TODO: comment on what each of these does
//                            filename.wstring().c_str(), // Preserve wchar_t
//                            GENERIC_READ, // if this is 0 I sounds like you cna query the device stats
//                            FILE_SHARE_READ, // You cannot request a sharing mode that conflicts with the access mode that is specified in an existing request that has an open handle.
//                            NULL, OPEN_EXISTING, // CREATE_ALWAYS
//                            FILE_ATTRIBUTE_READONLY | FILE_FLAG_SEQUENTIAL_SCAN | FILE_FLAG_NO_BUFFERING, 
//                            NULL
//                         );
//    if (hFile2 == INVALID_HANDLE_VALUE)
//    {
//        //throws error 0x20 (32) file being used by another process
//        std::cout << "\nCreateFile for hFile failed, error: " << GetLastError();
//        return 1;
//    }
//
//    int fd2 = _open_osfhandle((intptr_t)hFile2, _O_RDONLY);
//
//    if (fd2 == -1)
//    {
//        CloseHandle(hFile2);
//        std::cout << "\n_open_osfhandle failed, error: " << GetLastError();
//        return 1;
//    }
//
//    FILE* f2 = _fdopen(fd2, "r+"); // open file, writes appending after
//
//    if (f2 == 0)
//    {
//        _close(fd2); // Also calls CloseHandle()
//        std::cout << "\n_fdopen failed, error: " << GetLastError();
//        return 1;
//    }
//
//
//    // setup sector aligned buffer
//    LPVOID lpvBase;               // Base address of the test memory
//    //LPTSTR content;                 // Generic character pointer
//    BOOL bSuccess;                // Flag
//    SYSTEM_INFO sSysInfo;         // Useful information about the system
//    GetSystemInfo(&sSysInfo);     // Initialize the structure.
//
//    _tprintf (TEXT("This computer has page size %d.\n"), sSysInfo.dwPageSize);
//
//    dwPageSize = sSysInfo.dwPageSize;
//    uint64_t bytesToRead = 1207963648;
//    uint64_t remainder = (bytesToRead % dwPageSize); //Top it off
//    bytesToRead += (remainder == 0) ? 0 : (dwPageSize - remainder);
//    int seekResult = _fseeki64_nolock(f, 4096, SEEK_SET); // SEEK_SET is beginning of file readPosition must be a mult of the page size
//    if (seekResult != 0)
//    {
//        fclose(f); // Also calls _close()
//        std::cout << "\nseek failed, error: " << seekResult;
//    }
//
//    // Reserve pages in the virtual address space of the process.
//
//    lpvBase = VirtualAlloc( //addr returned is alligned on pageSize
//                     NULL,                 // System selects address
//                     bytesToRead, // Size of allocation // 
//                     MEM_RESERVE | MEM_COMMIT,          // Allocate reserved pages
//                     PAGE_READWRITE);       // PAGE_READONLY
//
//    if (lpvBase == NULL )
//        ErrorExit(TEXT("VirtualAlloc reserve failed."));
//
//    char* content = static_cast<char*>(lpvBase);
//    //memset(content, 0, bytesToRead);
//
//    //std::ifstream filestream(f);
//    //filestream.read(content, bytesToRead);
//    //printf("read: %s\n", content);
//    //std::ifstream fs2(f2);
//    //fs2.read(content, bytesToRead);
//    //printf("read: %s\n", content);
//    uint32_t bytesRead2 = fread(content, 1, bytesToRead, f2); // will not run if another has it open???
//    printf("read: %s\n btyes read: %d", content, bytesRead2);
//
//    // TRY OPENING A NEW hFile and deriving another _fdopen: did not work both fail
//    memset(content, 0, bytesToRead);
//    uint32_t bytesRead = fread(content, 1, bytesToRead, f); // will not run if another has it open???
//    printf("read: %s\n btyes read: %d", content, bytesRead);
//
//
//
//    //// Switch from read to write
//    //fseek(f, 0, SEEK_CUR); 
//    //const char* wbuffer = " --- Hello World! --- \n";
//    //fwrite(wbuffer, 1, strlen(wbuffer), f);
//
//    // Release the block of pages when you are finished using them.
//    bSuccess = VirtualFree(
//                       lpvBase,       // Base address of block
//                       0,             // Bytes of committed pages(must be 0 if using MEM_RELEASE to free everything)
//                       MEM_RELEASE);  // Decommit the pages
//
//    _tprintf (TEXT("Release %s.\n"), bSuccess ? TEXT("succeeded") : TEXT("failed") );
//
//    fclose(f); // Also calls _close()
//
//
//    return 0;
//}


//VOID _tmain(VOID)
//{
//    // Use structured exception handling when accessing the pages.
//    // If a page fault occurs, the exception filter is executed to
//    // commit another page from the reserved block of pages.
//
//    for (i=0; i < PAGELIMIT*dwPageSize; i++)
//    {
//        __try
//        {
//            // Write to memory.
//
//            lpPtr[i] = 'a';
//        }
//
//        // If there's a page fault, commit another page and try again.
//
//        __except ( PageFaultExceptionFilter( GetExceptionCode() ) )
//        {
//
//            // This code is executed only if the filter function
//            // is unsuccessful in committing the next page.
//
//            _tprintf (TEXT("Exiting process.\n"));
//
//            ExitProcess( GetLastError() );
//
//        }
//
//    }
//}




//// Move OS stuff somewhere else
//// windows.h is best to include in a single .cpp file with nothing else, and then expose wrappers in a header, which the rest of your code can use. If windows.h isn't visible, it can't conflict with your names.
//#define NOMINMAX // Tell window.h to not define min and max
//#include <windows.h>
////#include <tchar.h>
//#include <stdio.h>
////#include <stdlib.h>             // For exit
//#include <io.h>
//#include <fcntl.h>
////#include <cstdio>


        //Non-Blocking read on Windows (non-blocking write is probably more useful)
        //DWORD totalBytesRead = 0;
        //uint32_t offset = static_cast<uint32_t>(readPosition & 0x00000000FFFFFFFF);
        //uint32_t offsetHigh = static_cast<uint32_t>(readPosition & 0xFFFFFFFF00000000);
        //HANDLE hEvent = CreateEventA(
        //    NULL,
        //    TRUE,  // This means: Do I have to manually reset the signal state to get it to be false again?
        //    FALSE, // Initial signaled state
        //    NULL
        //);
        //OVERLAPPED overlapped;
        //overlapped.Offset = offset;
        //overlapped.OffsetHigh = offsetHigh;
        //overlapped.hEvent = hEvent;
        //BOOL readFileResult = ReadFile(
        //                                hFile,
        //                                baseAddress,
        //                                (DWORD)bytesToRead,
        //                                NULL,
        //                                &overlapped
        //                              );

        //if (!readFileResult && GetLastError() != ERROR_IO_PENDING)
        //{
        //    std::cout << "\nsomething failed with async IO";
        //}
        //else
        //{
        //    BOOL overlappedResult = GetOverlappedResult(
        //        hFile,
        //        &overlapped,
        //        &totalBytesRead,
        //        TRUE
        //    );
        //    bool readAllBytes = (totalBytesRead != bytesToRead && (bytesToRead - totalBytesRead) != endGap);
        //    if (overlappedResult == 0)
        //    {
        //        std::cout << "\nAsync read failed: (1 is success)" << overlappedResult;
        //    }
        //    else if(!readAllBytes)
        //    {
        //        std::cout << "\nAsync read did not read all bytes";

        //    }
        //}

    //PointClouds::PayloadInfo readFileNoBuffering(const fs::path& filename, uint64_t readPosition, uint64_t bytesToRead)
    //{
//          GRAB A FILE CHUNK NO BUFFERING WINDOWS
    //    // Error codes:
    //    // https://msdn.microsoft.com/en-us/library/cc231199.aspx

    //    // OS file reading writing not using buffering/caching
    //    // See Roy Longbottom's answer with Windows and Linux code
    //    // https://stackoverflow.com/questions/25899806/is-there-a-way-not-to-use-cache-in-c 

    //    // VirtualAlloc
    //    // example at bottom https://docs.microsoft.com/en-us/windows/desktop/Memory/reserving-and-committing-memory 
    //    // https://msdn.microsoft.com/library/windows/desktop/aa366887

    //    // CreateFile
    //    // https://docs.microsoft.com/en-us/windows/desktop/api/FileAPI/nf-fileapi-createfilea

    //    // FIle IO buffering
    //    // https://docs.microsoft.com/en-us/windows/desktop/FileIO/file-buffering
    //    // See answer about Windows calls (non-blocking IO calls, the ReadFileScatter is probably useless but WriteFileGather might be useful later)
    //    // https://stackoverflow.com/questions/13421767/multithread-read-from-disk


    //    //std::unique_lock<std::mutex> lock(test_mutex);



    //HANDLE hFile = CreateFileW(  //TODO: comment on what each of these does
    //                        filename.wstring().c_str(), // Preserve wchar_t
    //                        GENERIC_READ,// | GENERIC_WRITE,
    //                        FILE_SHARE_READ,// | FILE_SHARE_WRITE,
    //                        NULL, OPEN_EXISTING, // CREATE_ALWAYS
    //                        FILE_ATTRIBUTE_READONLY | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN,  //FILE_FLAG_RANDOM_ACCESS FILE_FLAG_WRITE_THROUGH FILE_FLAG_OVERLAPPED 
    //                        //FILE_FLAG_OVERLAPPED | FILE_ATTRIBUTE_READONLY | FILE_FLAG_NO_BUFFERING | FILE_FLAG_SEQUENTIAL_SCAN,  //FILE_FLAG_RANDOM_ACCESS FILE_FLAG_WRITE_THROUGH FILE_FLAG_OVERLAPPED 
    //                        NULL
    //                     );
    //    if (hFile == INVALID_HANDLE_VALUE)
    //    {
    //        std::cout << "\nCreateFile for hFile failed, error: " << GetLastError();
    //        return {nullptr, nullptr};
    //    }

    //    int fd = _open_osfhandle((intptr_t)hFile, _O_RDONLY);

    //    if (fd == -1)
    //    {
    //        CloseHandle(hFile);
    //        std::cout << "\n_open_osfhandle failed, error: " << GetLastError();
    //        return {nullptr, nullptr};
    //    }

    //    FILE* f = _fdopen(fd, "r"); // open file for reading

    //    if (f == 0)
    //    {
    //        _close(fd); // Also calls CloseHandle()
    //        std::cout << "\n_fdopen failed, error: " << GetLastError();
    //        return {nullptr, nullptr};
    //    }

    //    // setup sector aligned buffer
    //    SYSTEM_INFO sSysInfo;         // Useful information about the system
    //    GetSystemInfo(&sSysInfo);     // Initialize the structure.
    //    uint64_t dwPageSize = static_cast<uint64_t>(sSysInfo.dwPageSize);
    //    uint64_t moduloMask = dwPageSize - 1; //dwPageSize is always a pow2, used to AND with numbers to get the remainder of a divide

    //    uint64_t startGap = readPosition & moduloMask; // how far ahead our read position in the file is from a page boundary
    //    readPosition -= startGap; //set it back to the page boundary
    //    bytesToRead += startGap;
    //    uint64_t trailingBytes = bytesToRead & moduloMask;  
    //    uint64_t endGap = (dwPageSize - trailingBytes) & moduloMask; //moduloMask here is for the 0 case so we don't unnecessarily read and extra page
    //    bytesToRead += endGap; // Top it off to a multiple of page size

    //    // Using fseek for values grearter than max of int32_t
    //    // https://stackoverflow.com/questions/8708710/pass-a-value-greater-than-maximum-value-of-long-type-to-fseek-in-c
    //    //works on multiples of the page size need to put the readPostion on page start
    //    int seekResult = _fseeki64_nolock(f, readPosition, SEEK_SET); // SEEK_SET is beginning of file readPosition must be a mult of the page size
    //    if (seekResult != 0)
    //    {
    //        fclose(f); // Also calls _close()
    //        std::cout << "\nseek failed, error: " << seekResult;
    //        return {nullptr, nullptr};
    //    }

    //    // Reserve pages in the virtual address space of the process.
    //    LPVOID baseAddress = VirtualAlloc(                            // Addr returned is alligned on pageSize
    //                                        NULL,                     // NULL: System selects address
    //                                        bytesToRead + dwPageSize, // Size of allocation
    //                                        MEM_RESERVE | MEM_COMMIT, // Allocate reserved pages and commit them so we can use them, must do both flags to do anything with it
    //                                        PAGE_READWRITE);          // Other useful options: PAGE_READWRITE

    //    if (baseAddress == NULL)
    //    {
    //        std::cout << "\nERROR: VirtualAlloc Failed";
    //        return {nullptr, nullptr};
    //    }

    //    char* payloadBaseAddress = static_cast<char*>(baseAddress);

    //    //auto start = std::chrono::system_clock::now();
    //    // TODO Ticks 1,2,3,4,5 menaing the threads access the file one after the other (are queued)
    //    uint64_t totalBytesRead = _fread_nolock(payloadBaseAddress, 1, bytesToRead, f);

    //    if (totalBytesRead != bytesToRead && (bytesToRead - totalBytesRead) != endGap)
    //    {
    //        std::cout << "\nERROR: Only read " << totalBytesRead << " of " << bytesToRead << " bytes from position " << readPosition;
    //        // TODO how to suppress this if last read isnt a multiple of of the page size (actual file doesnt have the extra data we're reading)
    //    }
    //    fclose(f); // Also calls _close()
    //    //auto stop = std::chrono::system_clock::now();
    //    //std::cout << "\nProducer Elapsed Time(s): " << std::chrono::duration<double>(stop - start).count() << "\n";

    //    return { payloadBaseAddress + startGap, payloadBaseAddress, true };
    //}
    //struct PayloadInfo
    //{
    //    char* content;      // In the case of no buffered / no cached reads this is the first valid byte (baseAddress + jumpToFirstValidByte) 
    //    char* baseAddress;  // Needed to free the VirtualAlloc pages
    //    bool noBuffering = false;
    //};


        //if (rawPoints.noBuffering)
        //{
        //    // Release the block of pages when you are finished using them.
        //    bool bResult = VirtualFree(
        //        rawPoints.baseAddress,  // Base address of block
        //        0,            // Bytes of committed pages(must be 0 if using MEM_RELEASE to free everything)
        //        MEM_RELEASE); // Decommit the pages
        //    if (!bResult)
        //    {
        //        std::cout << "ERROR: VirtualFree Failed";
        //    }
        //    rawPoints.baseAddress = nullptr;
        //    rawPoints.content = nullptr;
        //}

