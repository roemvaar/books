#include <unistd.h>
#include <stdlib.h>

// File Descriptors - fildes
// 0 - Standard input
// 1 - Standard output
// 2 - Standard error

int main()
{
    char buffer[128];
    int nread;

    // size_t read(int fildes, void *buf, size_t nbytes);
    nread = read(0, buffer, 128);
    if(nread == -1) {
        write(2, "A read error has occurred\n", 26);
    }

    if((write(1, buffer, nread)) != nread) { 
        write(2, "A write error has occurred\n", 27);
    }

    exit(0);
}