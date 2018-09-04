#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    for(int i=0; i<2; i++){
        fork();
        printf("+\n");
    }
    return 0;
}
