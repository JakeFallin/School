#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#define CHARSZ 255

pid_t pid;

void mychar(char);
char* my_strncpy(char*, char*, int);
char** my_str2vect(char* x);
void my_str(char*);
int my_strcmp(char*, char*);
void my_signal(int);
int my_strlen(char*);
char* my_strnconcat(char*, char*, int);
char* my_strcpy(char*, char*);
char* my_strcat(char*, char*);

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



//signal helper for ctrl + c
void my_signal(int signal) {
	if(signal == SIGINT && pid > 0)
		kill(pid, SIGKILL);
}

int main(int argc, char** argv) {

	//starting variables
	char** i;
	char* string;
	char buffer[CHARSZ];
	int n;
	int r;
	pid_t pid;

	//signal for hardware interrupts
	signal(SIGINT, my_signal);

	//to get the program started
	if(argc > 1) {
		my_str("The correct command is: ./minishell\n");
	}
		my_str("[]---[]Welcome to Minishell[]---[]\n");

	//run till exited
	while(1) {
		//get the current working directory and print it
		getcwd(buffer, 1024);
		my_str(buffer);
		//and print the $
		my_str("$ ");
		//read in the input
		r = read(0, buffer, CHARSZ);
		if(r < 0) {
			my_str("Error in reading command\n");
			return 1;
		}
		//and terminating character
		buffer[r-1] = '\0';
		//convert the string into a vector deliminated by spaces
		i = my_str2vect(&buffer[0]);

		if(my_strcmp(i[0], "help") == 0) {
			my_str("List of Commands\nhelp: show all commands\nexit: exit the minishell\ncd: change the current directory\n");
		} else if(!my_strcmp(i[0], "cd")) {
			if(i[1] == NULL) {
				my_str("Please specify the directory you wish to cd to\n");
			} else {
				//change directory
				if(chdir(i[1]) == -1) {
					my_str("Invalid directory change\n");
				}
			}
		} else if(my_strcmp(i[0], "exit") == 0) {
			my_str("Exiting minishell\n");
			//free the memory
			for(int j = 0; i[j] != NULL; j++) {
				free(i[j]);
			}
			//exit
			exit(0);
			return 0;
		} else if(i[0] != NULL) {
			//if its not help, cd, or exit we fork
			pid = fork();

			//error
			if(pid < 0) {
				my_str("Error in the fork\n");
				return 1;
			//wait for process to finish
			} else if(pid > 0) {
				wait(NULL);
			//if its execution is invalid exit the fork
			} else {
				if((r = execvp(i[0], i)) < 0) {
					my_str(i[0]);
					my_str("Command invalid / Program cannot be executed\n");
					exit(0);
				}
			}
		//some other error
		} else {
			my_str("Error please retry or type help\n");
		}
	}
	//free the vector
	free(i);
	return 0;
}



