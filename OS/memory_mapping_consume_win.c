#include <windows.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    HANDLE hMapFile;
    LPVOID lpMapAddress;

    hMapFile = OpenFileMapping(FILE_MAP_ACCESS, /* R/W access */
        FALSE, /* no inheritance */
        TEXT("SharedObject") /* name of the mapped file object */
    );

    lpMapAddress = MapViewOfFile(hMapFile,  /* mapped object handle */
        FILE_MAP_ALL_ACCESS,  /* read/write access */
        0,  /* mapped view of entire file */
        0,
        0
    );

    /* read from shared memory */
    printf("Read message %s", lpMapAddress);

    UnmapViewOfFile(lpMapAddress);
    CloseHandle(hMapFile);
}