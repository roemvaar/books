#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

// To run this: TIMEFORMAT="" time ./copy_block
//
// Results for this example:
// 0.00user 0.00system 0:00.02elapsed 47%CPU (0avgtext+0avgdata 1084maxresident)k
//4952inputs+4952outputs (0major+57minor)pagefaults 0swaps


int main()
{
    char block[1024];
    int in;
    int out;
    int nread;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    
    while((nread = read(in, block, sizeof(block))) > 0)
        write(out, block, nread);

    exit(0);
}
