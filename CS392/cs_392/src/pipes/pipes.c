#include "my.h"
#include <sys/wait.h>
#include "stdio.h"
#include "errno.h"
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){
	pid_t pid1, pid2;
	int d[2];
	int dd[2];
	char dwrite[100];
	char ddwrite[100];
	int result;
	int result2;

	if(argc == 1){
		my_str("Usage: ./pipes <string args>\n");
		return 0;
	}
	char* x = my_vect2str(argv);
	if(pipe(d) == -1){
		my_str("Pipe error.\n");
		return 1;
	};
	if((pid1 = fork()) < 0){
		perror("fork error.");
	}
	if(pid1 == 0){
		result = read(d[0], &dwrite, 100);
		close(d[0]);
		if(result == -1){
			perror("Read error.");
		}
		if(pipe(dd) < 0){
			perror("Child pipe failed");
		}
		//print for the child
		my_str("Child: ");
		my_str(dwrite);
		my_char('\n');
		//write for the grandchild
		if(write(dd[1], dwrite, 100) == -1){
			perror("write error.");
		}
		if((pid2 = fork()) < 0){
			perror("forking to grandchild failed");
		}
		if(pid2 == 0){
			close(dd[1]);
			//this is the grandchild process
			result2 = read(dd[0], &ddwrite, 100);
			close(dd[0]);
			if(result2 < 0){
				perror("grandchild failed to read.");
			}
			wait(NULL);
			my_str("Grandchild: ");
			my_str(ddwrite);
			my_char('\n'); 	
			exit(EXIT_SUCCESS);
		}
		close(d[1]);
		wait(NULL);
		exit(EXIT_SUCCESS);
	}else{
		//print for parent
		my_str("Parent: ");
		my_str(x);
		my_char('\n');
		close(d[0]);
		if(write(d[1], x, 100) == -1){
			perror("write error.");
		}
		close(d[1]);
		wait(NULL);
	}
}
