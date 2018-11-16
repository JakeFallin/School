#include <stdio.h>
#include <signal.h>
#include <sys/select.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     	int sockfd, newsockfd, portno;
	int opt = 1;
     	socklen_t clilen;
     	//char buffer[256];
	char recbuf[256];
     	struct sockaddr_in serv_addr, cli_addr; 
	fd_set readfds;//set of file descriptors for connections
	int fdarray[1024];
	char unarray[1024][15];
	int curr;
	int max = 0;
	char temp[256];

     if (argc !=  2) {
         printf("Usage: ./server [port]\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
	//allow multiple clients just in case
     if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR,
		 (char*)&opt, sizeof(opt)) < 0){
		error("socket opt\n");
     }
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding\n");
     if(listen(sockfd,5) < 0)
	error("cant't listen\n");
     clilen = sizeof(cli_addr);
	//signal(SIGPIPE, SIG_IGN);
	while(1){
		FD_ZERO(&readfds);//zeros fd set
		FD_SET(sockfd, &readfds);//socket fd added
		max = sockfd;
		for(int x = 0; x < 1024; x++){
			if(fdarray[x] != 0){
				FD_SET(fdarray[x], &readfds);
			}
			if(fdarray[x] > max){
				max = fdarray[x];
			}
		}
		if(select(max+1, &readfds, 0, 0, 0) < 0){
			//error("Select error.\n");
		}
		
		//case: get something from a connection
		if(FD_ISSET(sockfd, &readfds)){
			newsockfd = accept(sockfd, 
				(struct sockaddr *) &cli_addr,
				&clilen);
			if(newsockfd < 0) error("error accepting child");

			bzero(recbuf, 256);
			if(read(newsockfd, recbuf, 255) < 0) error("child read");
			printf("New User: %s\n", recbuf);
			for(int ind = 0; ind < 1024; ind++){
				if(fdarray[ind] == 0){
					fdarray[ind] = newsockfd;
					strncpy(unarray[ind], recbuf, 14);
					//write(newsockfd, unarray[ind], 15);
					bzero(recbuf, 256);
					break;
				}
			}

		}
		for(int xx = 0; xx < 1024; xx++){
			curr = fdarray[xx];
			if(FD_ISSET(curr, &readfds)){
				int tst = read(curr, recbuf, 255);
				if(tst < 0) error("child reading error\n");
				if(tst == 0){
					fdarray[xx] = 0;
					break;
				}
				printf("%s\n", recbuf);	
				if(recbuf[0] == '/'){
					//exit
					if(strncmp(recbuf, "/exit", 5) == 0){
						//disconnect user
						close(curr);
						fdarray[xx] = 0;
					}else if(strncmp(recbuf, "/nick ", 6) == 0){
						//nick
						int gg = 0;
						for(int g = 0; g < strlen(&(recbuf[6])); g++){
							if(recbuf[g+6] != '\n' && recbuf[g+6] != ' ' && recbuf[g+6] != '	'){
								gg++;
							}
						}
						if(gg > 0){
							bzero(unarray[xx], 15);
							strncpy(unarray[xx], &(recbuf[6]), 14);
							strcat(unarray[xx], "\0");
							if(write(curr, "Name changed.\n", 14) < 0) error("well shit\n");
						}else{
							if(write(curr, "Name change failed.\n", 20) < 0) error("nmchange err\n");
						}
					}else if(strncmp(recbuf, "/me ", 4) == 0){
						//me
						for(int i = 0; i < 1024; i++){
						if(fdarray[i] != 0 && fdarray[i] != curr){
							bzero(temp, 256);
							strcpy(temp, strtok(unarray[xx], "\n"));
							strcat(temp, " ");
							strcat(temp, strtok(&(recbuf[5]), "\n"));
							if(write(fdarray[i], temp, 255) < 0) error("well shit\n");
						}
					}
					}else{
						//else
						write(curr, "Invalid command.", 16);
					}
				}else{
					for(int i = 0; i < 1024; i++){
						if(fdarray[i] != 0){
							bzero(temp, 256);
							strcpy(temp, strtok(unarray[xx], "\n"));
							strcat(temp, ": ");
							strcat(temp, strtok(recbuf, "\n"));
							if(write(fdarray[i], temp, 255) < 0) error("well shit\n");
						}
					}
				}
				bzero(recbuf, 256);
			}
		}
			
	}
     close(newsockfd);
     close(sockfd);
     return 0; 
}
