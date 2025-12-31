#include <unistd.h>
#include <stdio.h>
int main()
{
    // // return -1 if error and 0 for the chield and not 0 is for the main procrs
    // // and the nunber of process i get in rach fork call is 2^n
    // int id = fork();
    // if(id != 0)
    // {
    //     fork();
    // }
    // printf("id: %d\n", id);
    // printf("hii\n");

    // int id = fork();
    // int n;
    // if(id == 0)
    // {
    //     n = 1;
    // }
    // else
    // {
    //     n = 10;
    // }
    int fd[2];
    pipe(fd);
    int fd = fork();
}
