#include <windows.h>
#include <stdio.h>

/* Producer writing to the shared memory using Windows API */

int main(int argc, char* argv[])
{
    HANDLE hFile, hMapFile;     /* can use to examine or modify the system resource. */
    LPVOID lpMapAddress;        /* pointer to a void object */

    hFile = CreateFile("temp.txt", /* file name */
        GENERIC_READ | GENERIC_WRITE, /* read/write access */
        0, /* no sharing of the file */
        NULL, /* default security */
        OPEN_ALWAYS, /* open new or existing file */
        FILE_ATTRIBUTE_NORMAL, /* routine file attributes */
        NULL /* no file template */
    );

    hMapFile = CreateFileMapping(hFile, /* file handle */
        NULL, /* default security */
        PAGE_READWRITE, /* read/write access to mapped pages */,
        0, /* map entire file */,
        0,
        TEXT("SharedObject") /* named shared memory object */
    );

    lpMapAddress = MapViewOfFile(hMapFile, /* mapped object handle */
        FILE_MAP_ALL_ACCESS, /* read/write access */
        0, /* mapped view of entire file */
        0,
        0
    );

    /* write to the shared memory */
    sprintf(lpMapAddress, "Shared Memory message");

    UnmapViewOfFile(lpMapAddress);
    CloseHandle(hFile);
    CloseHandle(hMapFile);
}