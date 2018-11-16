#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int main() {

	char buffer[3];
	char *result;
	char *output;
	int key = 1;
	int keycount = 0;
	int n = 0;
	int c;
	result = (char*) malloc(1000);
	output = (char*) malloc(1000);

	FILE *file;
	size_t nread;
	file = fopen("encrypted.txt", "r");
	if(file == NULL) {
		printf("Cannot open file\n");
		exit(0);
	}
	else {
		// while ((nread = fread(buffer, 1, sizeof buffer, file)) > 0)
		// 	fwrite(buffer, 1, nread, stdout);
		// if(ferror(file)) {
		// 	printf("Error inside read");

		// }
		while((c = getc(file)) != EOF) {
			result[n++] = (char) c;
		}
		result[n] = '\0';

	fclose(file);
	}

	printf("\nResult %s", result);

	for(int i = 0; i < (n-1); i++) {
		char ch = result[i];
		printf("Keycount %d key: %d char:%c \n", keycount,key, ch);

		if(keycount == 3) {
				keycount = 0;
				key += 2;
			}

		 if(ch == '!') {
			//printf("!: R:%c CH:%c -- ", result[i], ch);
			output[i] = ch;
			keycount++;
		}
		 if(ch == ' ') {
			//printf("space: R:%c CH:%c -- ", result[i], ch);

			output[i] = ch;
			keycount++;
		} 

		if ((ch != '\0') && (ch != '!') && (ch != ' ') ) {
			//printf("other: R:%c CH:%c  -- ", result[i], ch);

			if(keycount == 3) {
				keycount = 0;
				key += 2;
			}
			if(ch >= 'a' && ch <= 'z') {
				//printf("LOWER");
				ch = ch - key;
				if(ch < 'a') {
					ch = ch + 'z' - 'a' + 1;
				}
				output[i] = ch;
			}
			if(ch >= 'A' && ch <= 'Z') {
				//printf("UPPER");

				ch = ch - key;
				if(ch < 'A') {
					ch = ch + 'Z' - 'A' + 1;
				}
				output[i] = ch;
			}
			keycount++;
			//printf(" end: R:%c CH:%c \n", result[i], ch);

		}
		


	}
	printf("\nOutput: %s", output);
	int filew;
	size_t nreadw;
	filew =  open("solution.txt", O_RDWR);
	write(filew, output, n-1);
	printf("\nSuccess!");

}