//
// Created by sadjad-pc on 1/15/17.
//

#include "types.h"
#include "stat.h"
#include "user.h"

#define  N  10    // child number
#define  print_num  10   // print number
void
do_test(void)
{
    int n, pid;
    int wTime;
    int rTime;

    printf(1, "3.1 test started.\n\n");

    for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0) // error
            break;
        if(pid == 0) { // child
            for (int i = 1; i <= print_num; i++) {
                printf(2, "Child %d prints for the %d time.\n", pid, i);
            }
            exit();
        }
    }

    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();
    wait();

    for(; n >= 0; n--){
        pid = getPerformanceData(&wTime, &rTime);
        printf(1, "wTime: %d rTime: %d \n",wTime,rTime);
    }
}

int
main(void)
{
    do_test();
    exit();
}
