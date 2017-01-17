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

    printf(1, "\n----------3.1 test started. parent_id : %d----------\n\n", getpid());

    for(n=0; n<N; n++){
        pid = fork();
        if(pid < 0) // error
            break;
        if(pid == 0) { // child
            for (int i = 1; i <= print_num; i++) {
                printf(2, " %d : Child %d prints for the %d time.\n", n, getpid(), i);
            }
            exit();
        }
    }

    printf(2,"\n");
    
    int child_pid[10];
    int wTime[10];
    int rTime[10];
    for(int i = 0; i < N; i++){
        child_pid[i] = getPerformanceData(&wTime[i], &rTime[i]);
    }
    for(int i = 0; i < N; i++){
        printf(1, "child : %d  =  wTime: %d rTime: %d \n",
               child_pid[i], wTime[i], rTime[i]);
    }

    printf(1, "\n----------3.1 test finished.----------\n\n");
}

int
main(void)
{
    do_test();
    exit();
}
