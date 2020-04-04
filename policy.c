#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
    if(argc != 2){
        printf(1, "you must add 1 arg of the new policy\n");
    }
    int new_policy = atoi(argv[1]);
    if(policy(new_policy) != 0){
        printf(1, "Error replacing policy, no such a policy number (%d)\n", atoi(argv[1]));
        exit(1);
    } else if(new_policy == 0){
        printf(1, "Policy has been successfully changed to Default Policy\n");
    } else if(new_policy == 1){
        printf(1, "Policy has been successfully changed to Priority Policy\n");
    } else if(new_policy == 2){
        printf(1, "Policy has been successfully changed to CFS Policy\n");
    }

  exit(0);
}
