/*	buf2
 *	integrated comand module execution via differential fusion
 *	lol jks it's just a buffer overflow
 *	shut up and smash the stack - pasteBin
 */

#include <stdio.h>
#include <stdlib.h>

void func(void);
void printFlag(void);

int main(int argc, char *argv[]) {
    func();
    return EXIT_SUCCESS;
}

void func(void) {
    printf("Hello what is your favourite type of poodle?\n");
    printf("ENTER POODLE CHOICE NOW> ");
    fflush(stdout);
    char array[50];
    scanf("%s",array);
    printf("oh.. i see\n");
    fflush(stdout);
}


void printFlag(void){

	FILE *fp;
	char ch[100];
	fp = fopen("~/flag.txt", "r");
	fgets(ch, 99, fp);
	fclose(fp);
	printf("The flag is %s", ch);
	fflush(stdout);
}





