#include "nsminishell.h"
#include <stdio.h>
#include <string.h>
#include "term.h"
#include "curses.h"
#include "ncurses.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/wait.h"
#include <signal.h>


char* my_strcpy(char *dst, char *src) 
{
	if(src == NULL && dst == NULL)
		return "";

	if(src==NULL)
	{
		return dst;
	}
	if(dst==NULL)
	{
		return src;
	}

	int i;

	for(i=0; src[i]!='\0'; i++)
	{
		dst[i]=src[i];
	}

	dst[i]='\0';

	return dst;
}


void my_char(char c)
{
	write(1, &c, 1);
}

void my_str(char* str) 
{
	if(str != NULL) 
	{
		int i = 0;
		while(str[i] != '\0')
		{
			my_char(str[i]);
			i++;
		}
	}
}

char* my_strncpy(char *dst, char *src, int n) 
{
	if(src == NULL && dst == NULL)
		return "";
	
	if(src==NULL)
	{
		return dst;
	}
	if(dst==NULL)
	{
		return src;
	}

	int dstl=my_strlen(dst);
	int srcl=my_strlen(src);
	int lim=n;

	if(srcl<lim)
		lim=srcl;

	int i;

	for(i=0; i<lim; i++)
	{
		dst[i]=src[i];
	}

	dst[i]='\0';

	return dst;
}


int my_strcmp(char *a, char *b)
{
	if(a==NULL && b==NULL)
		return 0;
	if(a==NULL)
		return -1;
	if(b==NULL)
		return 1;

	int la=my_strlen(a);
	int lb=my_strlen(b);

	for(int i=0; i<la && i<lb; i++)
	{
		if(a[i]<b[i])
			return -1;
		if(a[i]>b[i])
			return 1;

	}

	if(la<lb)
		return -1;
	if(la>lb)
		return 1;

	return 0;
}

int my_strlen(char* string) 
{
	if(string == NULL) 
	{
		return -1;
	}

	char* e="";
	if(string==e)
	{
		return 0;
	}

	int len = 0;
	int i=0;

	while(string[i] != '\0') 
	{
		len++;
		i++;
	}
	return len;
}

char* my_strcat(char *dst, char *src) 
{

	if(dst == NULL || src == NULL) 
		return dst;

	int dstl = my_strlen(dst);
	int srcl = my_strlen(src);

	int i;

	for(i = 0; ((i < srcl) && (src[i] != '\0')); i++) 
	{
		dst[dstl + i] = src[i];
	}
	dst[dstl + i] = '\0';
	return dst;
}

char* my_strnconcat(char *a, char *b, int n) 
{

	int al = my_strlen(a);
	int bl = my_strlen(b);
	

	if(a==NULL && b==NULL)
		return NULL;
	if(n<bl)
		bl=n;

	char* result = malloc(al+bl+1);
	int i;

	for(i=0; i<al; i++)
	{
		result[i]=a[i];
	}
	for(i=0; i<bl; i++)
	{
		if(a==NULL || a[0]=='\0')
			result[i]=b[i];
		else
			result[i+al]=b[i];
	}

	if(a==NULL || a[0]=='\0')
		result[bl+1]='\0';
	else if(b==NULL || b[0]=='\0')
		result[al+1]='\0';
	else
		result[al+bl+1]='\0';

	return result;

}

char** my_str2vect(char* str){
		
	//initialize varibles
	int index = 0, wordCount = 0, wordLength = 0, strLength;
	//in order to concat the string need a first empty argument
	char* empty = "";
	strLength = my_strlen(str);
	//malloc the vector
	char** vector = (char **)malloc((strLength+1) * sizeof(char*));
	
	
	//only do this while there is a string
	if(str != NULL) {

		//while not at the end of the string
		while(str[index] != '\0'){
			//check to see if theres a deliminating character
			if(str[index] == ' ' || str[index] == '\t' || str[index] == '\n') {
				//if its the first index just skip
				if(wordLength == 0) {
					str++;
				}
				//in this case we have to split the vector
				//split the vector on the wordLength and increase word count
				vector[wordCount] = my_strnconcat(empty, str, wordLength);
				wordCount++;
				//increase string based up the string we just added to vector
				str += (wordLength+1);
				//reset
				index = 0;
				wordLength = 0;
			//here we just increment
			} else {
				index++;
				wordLength++;
			}
		}
		//needs to be done once at the very least
		vector[wordCount] = my_strnconcat(empty, str, wordLength);
		//and make the last one null
		vector[wordCount+1] = NULL;
		return vector;
	//otherwise just return nothing
	} else {
		return vector;
	}
}

int main(int argc, char** argv) {
	//init variables
	char inputLength = 0;
	char cwd[1024];
	char* clipboardString = (char*)malloc(256*sizeof(char));
	char* inputString = (char*)malloc(256*sizeof(char));
	char* currentDirectory;
	char** inputCommand;
	int curX, curY, inputLetter, r;
	int pid = 0, index = 0;


	//init ncurses window and general setup
	initscr();	
	refresh();
	clear();		
	keypad(stdscr, TRUE);
	noecho();
	move(0, 0);

	while(1) {
		//no input
		inputLength = 0;

		//print minishell
		printw("minishell: ");
		refresh();

		//get current directory
		getcwd(cwd, sizeof(cwd));

		if(sizeof(cwd) > 0) {
			printw(cwd);
			refresh();
		}
		//print $
		printw("$: ");

		//get input for commands
		while(inputString[inputLength] != '\0') {
			inputString[inputLength] = '\0';
			inputLength++;
		}

		//set back to zero for input of single keys or CTRL+
		inputLength = 0;

		while((inputLetter = getch()) != '\n') {
   			
   			getyx(curscr, curY, curX);
			
			//move left
			if(inputLetter == KEY_LEFT) {
				if(inputLength > 0) {
					move(curY, curX - 1);
					inputLength--;
					refresh();
				} else {
					move(curY, curX);
					refresh();
				}
			//move right
			} else if(inputLetter == KEY_RIGHT) {
				move(curY, curX+1);
				refresh();
			//didngt have time to implement these
			} else if(inputLetter == KEY_UP) {
				refresh();
			} else if(inputLetter == KEY_DOWN) {
				refresh();
			} else if(inputLetter == KEY_BACKSPACE) {
				refresh();	
			//move to start of command
			} else if(strcmp(keyname(inputLetter), "^A") == 0) {
				getyx(stdscr, curY, curX);
				move(curY, inputLength);
				refresh();
				inputLength = 0;
			//move to end of command
			} else if(strcmp(keyname(inputLetter), "^E") == 0) {
				getyx(stdscr, curY, curX);
				move(curY, inputLength + my_strlen(inputString));
				refresh();	
			//clear terminal			
			} else if(strcmp(keyname(inputLetter), "^L") == 0) {
				refresh();
				clear();
				printw(cwd);
				printw(" $: ");
				printw(inputString);
			//cut input to clipboard
			} else if(strcmp(keyname(inputLetter), "^U") == 0) {
				my_strcpy(clipboardString[inputLength], inputString);
				refresh();
				inputLength = 0;
			//cut word to clipboard
			} else if(strcmp(keyname(inputLetter), "^W") == 0) {
				int t = inputLength;
				for(;t != ' '; t--) {
					clipboardntsString[t] = inputString[t];
				}
				inputLength = my_strlen(clipboardString);
				refresh();
			//paste
			} else if(strcmp(keyname(inputLetter), "^Y") == 0) {
				if(my_strcmp(clipboardString, "\0") != 0) {
					addch(clipboardString);
					inputLength = my_strlen(clipboardString);
					inputString = clipboardString;
				}
				refresh();
			//setup for commands
			} else {
				refresh();
				inputLength++;
				inputString[inputLength-1] = inputLetter;
				addch(inputLetter);
			}
		}
		//fix input string and start newline
		inputLength = my_strlen(inputString);
		inputString[inputLength] = '\0';
		addch('\n');

		//same as minishell
		if (inputLength >= 1) {
			inputCommand = my_str2vect(inputString);
					if(my_strcmp(inputCommand[0], "help") == 0) {
			printw("List of Commands\nhelp: show all commands\nexit: exit the minishell\ncd: change the current directory\n");
		} else if(!my_strcmp(inputCommand[0], "cd")) {
			if(inputCommand[1] == NULL) {
				printw("Please specify the directory you wish to cd to\n");
			} else {
				//change directory
				if(chdir(inputCommand[1]) == -1) {
					printw("Invalid directory change\n");
				}
			}
		} else if(my_strcmp(inputCommand[0], "exit") == 0) {
			printw("Exiting minishell\n");
			//free the memory
			for(int j = 0; inputCommand[j] != NULL; j++) {
				free(inputCommand[j]);
			}
			//exit
			exit(0);
			return 0;
		

		} else if(inputCommand[0] != NULL) {
			//if its not help, cd, or exit we fork
			pid = fork();

			//error
			if(pid < 0) {
				printw("Error in the fork\n");
				return 1;
			//wait for process to finish
			} else if(pid > 0) {
				wait(NULL);
			//if its execution is invalid exit the fork
			} else {
				if((r = execvp(inputCommand[0], inputCommand)) < 0) {
					printw(inputCommand[0]);
					printw("Command invalid / Program cannot be executed\n");
					exit(0);
				}
			}
		//some other error
		} else {
			printw("Error please retry or type help\n");
		}
		}
	}
	endwin();
	free(inputString);
	return 0;
}