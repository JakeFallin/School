#define _POSIX_SOURCE
#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#define h_addr h_addr_list[0] 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    	int sockfd, portno;
	pid_t pid;
	int validusername = 0;
	int cntun = 0;
    	struct sockaddr_in serv_addr;
    	struct hostent *server;
	//char user[256];
    	char buffer[256];
	char recv[256];
    if (argc !=  3) {
       printf("Usage: ./client [host] [port]\n");
       exit(1);
    }
	while(!validusername){
		//get the username
		bzero(buffer, 256);
		printf("Username: ");
		fgets(buffer,255,stdin);
		for(int g = 0; g < strlen(buffer); g++){
			if(buffer[g] != '\n' && buffer[g] != ' ' && buffer[g] != '	'){
				cntun++;
			}
		}
		if(cntun > 0){
			validusername = 1;
		}else{
			bzero(buffer, 256);
		}
	}
	//connect
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
	//send the username to server 
	if(write(sockfd, buffer, 255) < 0) error("error setting username\n");
	
	//fork so we can listen and write omg wow
	if((pid = fork()) < 0){
		//error
		error("forking is jank\n");
	} else if(pid == 0){
		//child
		while(1){
			bzero(recv, 256);
			if(read(sockfd,recv,255) < 0) error("read error\n");
			printf("%s\n", recv);
		}
	}else{
		//parent
		while(1){
			fgets(buffer, 255, stdin);
			//exit if exit
			if(strncmp(buffer, "/exit", 5) == 0){
				close(sockfd);
				printf("Bye!\n");
				kill(0, SIGKILL);
				kill(1, SIGKILL);
			}
			if(write(sockfd, buffer, strlen(buffer)) < 0){
				kill(0, SIGKILL);
				error("write error");
			}
			bzero(buffer, 256);
		}
	}
    close(sockfd);
    return 0;
}
