//
// Created by sadjad-pc on 1/17/17.
//

#include "types.h"
#include "stat.h"
#include "user.h"

#define print_num   50

void print(){
    for(int i = 1 ; i <= print_num; i++)
    {
        printf(1 , "process <%d> is printing for the <%d> time.\n" , getpid() , i);
    }
}

void
do_test(void)
{
    printf(1 , "Father pid :  %d\n" , getpid());
    sleep(1000);

    int pid = fork();

    if(pid < 0){
        printf(1 ,"fork failed!\n");
    }else if (pid == 0){ // child
        print();
        exit();
    }else{ // parent
        wait();
        print();
    }
}

int
main(void)
{
    do_test();
    exit();
}
