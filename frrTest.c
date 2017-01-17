//
// Created by sadjad-pc on 1/16/17.
//


#include "types.h"
#include "stat.h"
#include "user.h"

#define  N  10    // child number
#define  wait_num  1000   // print number

void
do_test(void)
{
    int n, pid;

    printf(1, "\n----------3.2 test started.----------\n\n");

    for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0) // error
            break;
        if(pid == 0) { // child
            for (int i = 1; i <= wait_num; i++) {
                printf(1, "n : %d, child %d\n", n, getpid());
            }
            exit();
        }
    }

    printf(2,"\n");

    for(int i = 0; i < N; i++){
        wait();
    }

    printf(1, "\n----------3.2 test finished.----------\n\n");
}

int
main(void)
{
    do_test();
    exit();
}
