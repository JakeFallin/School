#define _POSIX_SOURCE
#include "my.h"
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#define MAX 255

pid_t pid;

//has some trouble handling ctrl c if a second minishell is created
int main(int argc, char const *argv[]){
	char buffer[MAX];
	int rd;
	int x;
	char** cmd;
	
	if(argc > 1){
		my_str("Usage: ./minishell");
	}
	signal(SIGINT, SIG_IGN);
	while(1){
		my_str("SADshell:~");
		getcwd(buffer, 1024);
		my_str(buffer);
		my_str("$ ");
		rd = read(0, buffer, MAX);
		buffer[rd-1] = '\0';
		
		cmd = my_str2vect(&(buffer[0]));
		if(my_strcmp("exit", cmd[0]) == 0){
			for(x = 0; cmd[x] != NULL; x++){
				free(cmd[x]);
			}
			free(cmd);
			my_str("Hasta la pasta, hombre.\n");
			kill(0, SIGKILL);
		}else if(my_strcmp("help", cmd[0]) == 0){
			my_str("help: \t\tLists built-in functionality.\n");
			my_str("exit: \t\tExits the SadShell\n");
			my_str("cd [path]: \tChanges to specified directory.\n");
		}else if(my_strcmp("cd", cmd[0]) == 0){
			if(cmd[1] == NULL){
				my_str("I need a place to go: cd [path]\n");
			}else{
				if(chdir(cmd[1]) != 0){
					my_str("Can't go there\n");
				}
			}
		}else{
			if((pid = fork()) < 0){
				my_str("Forking failure.\n");
				continue;
			}
			if(pid > 0){
				wait(NULL);
			}else{
				if(execvp(cmd[0], cmd) < 0){
					my_str(cmd[0]);
					my_str(" isn't something I can do.\n");
				}
			//	exit(EXIT_SUCCESS);
			}
		}
	}
	return 0;
}
