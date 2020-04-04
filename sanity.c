#include "types.h"
#include "stat.h"
#include "user.h"

void childs_code(int child_number){
    struct perf performence;
    int ps_priotiry = 0;
    int i = 100000000;
    // int dummy = 0;
    switch (child_number)
    {
    case 1:
        ps_priotiry = 1;
        break;
    case 2:
        ps_priotiry = 5;
        break;
    case 3:
        ps_priotiry = 10;
        break;
    }
    set_cfs_priority(child_number);
    set_ps_priority(ps_priotiry);
    while(i--){
        // dummy+=i;
        printf(1,"");
    }
    proc_info(&performence);
    printf(1, "%d      %d           %d        %d        %d\n", getpid(), performence.ps_priority, performence.stime, performence.retime, performence.rtime);
}

int
main(int argc, char *argv[])
{ 
    int status;
    printf(1, "%s    %s    %s    %s    %s\n", "PID", "PS_PRIORITY", "STIME", "RETIME", "RTIME");
    int pid[3];
    int i = 1;
    pid[i] = fork();
    if( pid[i] == 0){
        childs_code(i);
        exit(0);
    }
    i++;
    pid[i] = fork();
    if( pid[i] == 0){
        childs_code(i);
        exit(0);
    }
    i++;
    pid[i] = fork();
    if( pid[i] == 0){
        childs_code(i);
        exit(0);
    }
    wait(&status);
    wait(&status);
    wait(&status);
    exit(0);
}
