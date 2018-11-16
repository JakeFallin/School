void my_char(char c)
	{
		/*Write the contents of c to standard out, which is file descriptor 1*/
		write(1, &c, 1);
	}

void my_str(char* str) {
	if(str != NULL) {
		int i = 0;
		while(str[i] != '\0') {
			my_char(str[i]);
			i++;
		}
	}
}

void my_int(int num) {
	//fuck this one
}

void my_alpha() {
	char letter = 'A';
	for(letter='A'; letter <= 'Z'; letter++) {
		my_char(letter);
	}
}

void my_digits() {
	char num = '0';
	for(num='0'; num <= '9'; num++) {
		my_char(num);
	}
}

int my_strindex(char* string, char match) {
	if(string == NULL) {
		return -1;
	} 
	while(*string != '\0') {
		if(*string == match) {
			return string;
		}
		string++;
	}
	return -1;
}

//this one is prob not working
int my_strrindex(char* string, char match) {
	if (string == NULL) {
		return -1;
	}
	int matches;
	while(*string != '\0') {
		if(*string == match) {
			matches = string;
		}
	}
	return matches;
}

int my_strlen(char* string) {
	if(string == NULL) {
		return -1;
	}
	int len = 0;
	while(string != '\0') {
		len++;
	}
	return len;
}
