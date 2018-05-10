#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main () {
	int pid;
	if ((pid = fork ()) != 0) {
		printf("Father\n");
	}
	else if ((pid = fork ()) != 0){
		printf("Son\n");
	}
	else printf("Grandson\n");

}
