
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <curses.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <fcntl.h>
#include <signal.h>

int screenWidth, screenHeight;


void refreshScreenSize() {

	struct winsize screenSize;
	ioctl(fileno(stdout), TIOCGWINSZ, &screenSize);
	screenHeight = screenSize.ws_row;
	screenWidth = screenSize.ws_col;

}

int main(int argc, char* argv[]) {

	if(argc < 2) {
		my_str("Please use as: ./myselect file1 file2 ...\n");
		exit(1);
	}

	clear();
	move(0,0);

	int maxLen;

	int* itemHighlighted;
	char* itemName;
	int* itemLength;
	int totalSize;

	for(int i = 0; i < argc; i++) {
		itemHighlighted[i] = 0;
		itemName[i] = argv[i];
		itemLength[i] = strlen(argv[i]);
		totalSize++;
	}


	initscr();
	curs_set(0);
	raw();
	noecho();
	refreshScreenSize();

	while(1) {

		int c = getch();

		if(c == ' ') {

		}
		else if(c == 27) {
			endwin();
		}
		else if(c == 10) {
			endwin();
			break;
		}
		else if(c == KEY_LEFT) {

		}
		else if(c == KEY_RIGHT) {

		}
		else if(c == KEY_DOWN) {

		}
		else if(c == KEY_UP) {

		}
		else if(c == KEY_RESIZE) {
			refreshScreenSize();
		}


	}
	for(int i = 0; i )


}