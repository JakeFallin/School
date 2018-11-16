#define _POSIX_SOURCE
#include <strings.h>
#include "my.h"
#include "list.h"
#include <curses.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <term.h>
#include <termios.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/types.h>
#include <stdarg.h>

#define MAX 255
#define MAX_PATH 4096
#define BUFF 4096

pid_t pid;
struct termios original;
bool going = 0;

//get console out of raw mode
void go_std(){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &original);
}

//get console into raw mode
void go_raw(){
    static struct termios std;
    
    tcgetattr(STDIN_FILENO, &std);
    atexit(go_std);

    struct termios rawmode = std;
    //canonical mode off -- lets me define input processing
    rawmode.c_lflag &= ~(ICANON | IEXTEN);
    //turn off echo
    rawmode.c_lflag &= ~(ECHO | ECHONL);
    //disable signals so i can define behaviour
    //rawmode.c_lflag &= ~ISIG;

    //makes enter put stuff on new line? carriage return?
    rawmode.c_iflag |= ICRNL;
    //tbh i dont get this one but the internet says so
    //something about new line not getting made -> CR
    rawmode.c_iflag &= ~INLCR;

    //use my onput processing -- OUTPUTS
    rawmode.c_oflag |= OPOST;
    //make the newline (enter) into CR and newline
    rawmode.c_oflag |= ONLCR; 
    //i think this makes it not output CR
    rawmode.c_oflag &= ~(OCRNL | ONOCR | ONLRET);

    rawmode.c_cc[VMIN] = 1; //gotta read one char
    //when time is less than min it doesnt time out i think
    rawmode.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &rawmode);
}

//printing the appropriate prompt and setting key mode thing
void sad_prompt(){
    char path[MAX_PATH];
    getcwd(path, sizeof path);

    //keypad mode
    putp(tigetstr("smkx"));
    
    putp(tparm(tigetstr("setaf"), COLOR_MAGENTA));
    printf("%s", "SADshell:");
    //could do the color switching for goodbadcmds
    putp(tparm(tigetstr("setaf"), COLOR_CYAN));
    printf("~%s", path);
    putp(tparm(tigetstr("setaf"), COLOR_GREEN));
    printf("➜ ");

    //reset colors
    putp(tigetstr("sgr0"));
}
void process(){
    char buffer[MAX];
    int rd;
    int x;
    char** cmd;

    rd = read(0, buffer, MAX);
    buffer[rd-1] = '\0';

    cmd = my_str2vect(&(buffer[0]));
    if(my_strcmp("exit", cmd[0]) == 0){
        for(x = 0; cmd[x] != NULL; x++){
            free(cmd[x]);
        }
        free(cmd);
        going = false;
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
            return;
        }
        if(pid > 0){
            wait(NULL);
        }else{
            if(execvp(cmd[0], cmd) < 0){
                my_str(cmd[0]);
                my_str(" isn't something I can do.\n");
            }
        }
    }

}
void get_input(){
    char buffer[BUFF];
    //int histpos = 0;
    bool gogo = true;
    bzero(buffer, BUFF);
    
    while(gogo){
        //history movement here
        //for(struct s_node ...
    }

}

int main(int argc, char const *argv[]){
    int err;
    //proper usage
    if(argc > 1){
        my_str("Usage: ./nsminishell");
    }

    //set buffering to none
    setvbuf(stdout, NULL, _IONBF, 0);
    //setvbuf(stderr, NULL, _IONBF, 0);

    if(setupterm(NULL, 1, &err)!= OK){
        puts("Setupterm: Terminal issue.");
        return 1;
    }
    //only exit can kill
    //signal(SIGINT, SIG_IGN);
    //set into rawmode with no buffered input
    go_raw();
    
    going = true;
    while(going){
        sad_prompt();
        get_input();
        return 0;
    }
    
    putp(tigetstr("rmkx")); //keypad off jic

    puts("Bye dood.");

    return 0;
}
