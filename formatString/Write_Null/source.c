/*
 | Easy format string CTF challenge
 | The aim is to write a null to a variable you have the address of
 | compile with 'gcc source.c -o format_string -Wall -m32'
 | by pasteBin for the COMP3441 Security course
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *	   ____                    __        __      _             *	
 *	  / __/__  ______ _  ___ _/ /_  ____/ /_____(_)__  ___ _   *	
 *	 / _// _ \/ __/  ' \/ _ `/ __/ (_.-/ __/ __/ / _ \/ _ `/   *	
 *	/_/  \___/_/ /_/_/_/\_,_/\__/ /___/__/ _/ /_/_//_/\_, /    *	
 *	                                                 /___/     *	
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <stdio.h>
#include <stdlib.h>

void do_the_format(void);

int main(int argc, char *argv[]){
	printf(
"   ____                    __        __      _            	\n"
"  / __/__  ______ _  ___ _/ /_  ____/ /_____(_)__  ___ _  	\n"
" / _// _ \\/ __/  ' \\/ _ `/ __/ (_.-/ __/ __/ / _ \\/ _ `/  	\n"
"/_/  \\___/_/ /_/_/_/\\_,_/\\__/ /___/__/ _/ /_/_//_/\\_, /   	\n"
"                                                 /___/    	\n"
	);
	fflush(stdout);
	do_the_format();
	return EXIT_SUCCESS;
}

void do_the_format(void){
	char format_string[101];
	char change_this = 0x41;
	printf("Once thought to be just a lazy short cut,\n"
		"actually leads to remote code execution!\n\n"
		"We have a variable at %p which equals 0x%x\n"
		"Use the power of the format string vuln to\n"
		"make this 0x00\n"
		"format string> ", &change_this, change_this);
	fflush(stdout);
	fgets(format_string, 99, stdin);
	format_string[100] = '\0';
	printf(format_string); // I feel dirty typing this
	fflush(stdout);
	if (change_this != 0x41){
		if (change_this == 0x00){
			printf("COMP3441{memory_sniping_with_the_format_string_is_fun}\n");
		}else{
			printf("You have changed the variable to %x\n", change_this);
		}
		fflush(stdout);
	}
}


