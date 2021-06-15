#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

// To run this: TIMEFORMAT="" time ./copy_sytem
//
// Results for this example:
// roemvaar@rob:~/repos/books/linux-programming/3-files$ TIMEFORMAT="" time ./copy_system 
// 1.46user 4.85system 0:06.33elapsed 99%CPU (0avgtext+0avgdata 1180maxresident)k
// 0inputs+4960outputs (0major+59minor)pagefaults 0swaps

int main()
{
    char c;
    int in;
    int out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    
    while(read(in, &c, 1) == 1){
        write(out, &c, 1);
    }

    exit(0);
}
