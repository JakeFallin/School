#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>
#include <ncurses.h>
#include <limits.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

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

int curx = 0, cury = 0, x = 0, y = 0, cha = 0;
char dir[4096];
int promptLen; 
char* line;
char* clip;
WINDOW* win;
int scrWidth, scrHeight;
 



void refreshScreenSize() {

	struct winsize screenSize;
	ioctl(fileno(stdout), TIOCGWINSZ, &screenSize);
	scrHeight = screenSize.ws_row;
	scrWidth = screenSize.ws_col;

}


//signal helper for ctrl + c
void my_signal(int signal) {
	if(signal == SIGINT && pid > 0)
		kill(pid, SIGKILL);
}


void delete_line(WINDOW* win) {

	getyx(win, cury, curx);
	while(curx > promptLen) {
		curx--;
		delch();
		move(cury, curx);
	}
	move(cury, curx+1);
}

void inp(char c) {

		promptLen =my_strlen(dir) + 16;
		//CTRL + Y
		if(c == 25) {
			my_str(clip);
			my_strcpy(line[cha], clip);
			cha = my_strlen(line);


		//CTRL + L
		} else if(c ==  12) {
			clear();
			my_str(line);


		//CTRL + A
		} else if(c == 1) {
			getyx(win, cury, curx);
			move(cury, promptLen);


		//CTRL + E
		} else if(c == 5) {

			getyx(win, cury, curx);
			move(cury, my_strlen(line));

		//CTRL + W
		} else if(c == 23) {

			
		//CTRL + U
		} else if(c == 21) {


		//UP
		} else if(c == KEY_UP) {
			delete_line(win);
			memset(line, 0, 1024);
			my_str(clip);

		//DOWN
		} else if(c == KEY_DOWN) {

			delete_line(win);
			memset(line, 0, 1024);
		
		//LEFT
		} else if(c == KEY_LEFT) {
			move(0,0);

		//RIGHT
		} else if(c == KEY_RIGHT) {
			move(0,0);

		//BACKSPACE
		} else if(c == KEY_BACKSPACE) {
			delete_line(line);
			move(0,0);
			memset(line, 0, 1024);
		
		}

}


int main(int argc, char** argv) {

	//starting variables
	char** i;
	char* string;
	char buffer[CHARSZ];
	int inputL;
	int r;
	int store = 0;
	char cwd[1024];
	pid_t pid;
	char* s = (char*) malloc(256*sizeof(char));
	line = malloc(1024);
	memset(line, 0, 1024);
	clip = malloc(1024);
	memset(clip, 0, 1024);
	initscr();
	int n = 0;
	//signal for hardware interrupts
	//signal(SIGINT, my_signal);

	clear();
	raw();
	noecho();
	refreshScreenSize();


	//to get the program started
	if(argc > 1) {
		my_str("The correct command is: ./minishell\n");
	}
		my_str("[]---[]Welcome to Minishell[]---[]\n");

while (s[n] != '\0')
		{
			s[n] = '\0';
			n++;
		}

		n = 0;
	//run till exited
	while(1) {
		//get the current working directory and print it
		printw("MINISHELL:");
		refresh();

		printw(" $: ");
		refresh();
if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			printw(cwd);
			refresh();
			store = (my_strlen(cwd) + 14);
		}

		else
		{
			printw("Error in current directory");
			refresh();
			return -1;
		}

		// getcwd(buffer, 1024);
		// my_str(buffer);
		// //and print the $
		// my_str("$ ");
		// //read in the input
		// r = read(0, buffer, CHARSZ);
		// if(r < 0) {
		// 	my_str("Error in reading command\n");
		// 	return 1;
		// }
		// //and terminating character
		// buffer[r-1] = '\0';
		// //convert the string into a vector deliminated by spaces
		// i = my_str2vect(&buffer[0]);

		while((inputL = getch()) != '\n') {
			getyx(curscr, cury, curx);
			refresh();


		addch('\n');
		n = my_strlen(s);
		s[n] = '\0';

		if(n>=0) {

			i = my_str2vect(s);

			
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

	}
}
	//free the vector
	free(i);
	return 0;
}



