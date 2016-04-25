/*
 *	buf1.c
 *	demonstrating a simple bufferoverflow
 *
 *	by pasteBin (Jordan)
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	printf("Enter some stuff:");
	fflush(stdout);

	char buf[16];
	int magic = 1;
	scanf("%s",buf);
	printf("You entered %s \nmagic = %d\n", buf, magic);
	if (magic == 'T'){
		printf("Now the magic is really happening\n");
		fflush(stdout);
		execve("/bin/sh", NULL, NULL);
	}


	return EXIT_SUCCESS;

}
	
	
