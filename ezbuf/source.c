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


	char buff[9447];
	printf(">> this one should be easy ;) <<\n%p", buff);

	scanf("%s",buff);

	printf("You entered %s\n", buff);


	return EXIT_SUCCESS;

}
	
	
