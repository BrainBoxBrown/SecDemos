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
void print_the_flag(void);

int main(int argc, char *argv[]){
	printf(
"   ____                    __        __      _            	\n"
"  / __/__  ______ _  ___ _/ /_  ____/ /_____(_)__  ___ _  	\n"
" / _// _ \\/ __/  ' \\/ _ `/ __/ (_.-/ __/ __/ / _ \\/ _ `/  	\n"
"/_/  \\___/_/ /_/_/_/\\_,_/\\__/ /___/__/ _/ /_/_//_/\\_, /   	\n"
"                                                 /___/    	\n"
// "┌┬┐┬ ┬┌─┐  ┌─┐┬┌─┐\n"
// " │ ├─┤├┤   ├┤ │├─┘\n"
// " ┴ ┴ ┴└─┘  └─┘┴┴  \n"
" +-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+\n"
" |c h a n g i n g| |t h e| |e i p|\n"
" +-+-+-+-+-+-+-+-+ +-+-+-+ +-+-+-+\n"



	);
	fflush(stdout);
	do_the_format();
	return EXIT_SUCCESS;
}

void do_the_format(void){
	char format_string[101];
	printf("Once thought to be just a lazy short cut,\n"
		"actually leads to remote code execution!\n\n"
		"We have a function at %p which prints the flag\n"
		"The power of the format string vuln will\n"
		"guide you to this function.\n"
		"format string> ", print_the_flag);
	fflush(stdout);
	fgets(format_string, 99, stdin);
	format_string[100] = '\0';
	printf(format_string); // I feel dirty typing this
	puts("Having fun?");xp
	fflush(stdout);
}

void print_the_flag(void){
	printf("COMP3441{flag}\n");
	fflush(stdout);
}


