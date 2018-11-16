#include "../include/my.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

int main(int argc, char const *argv[]){
    
//	my_int(my_strcmp("fa", "cd"));
/*
	my_str("hi there all \n");
	my_str(NULL);
	my_char('\n');
	my_str("2342423\n");
	my_str("");
	my_int(45);
	my_int(-2342);
	my_str("i need this zero\n");
	my_int(my_strlen(""));
	my_char('\n');
	my_str("testing vect2str\n");
	char*  vector[4] = {"hi", "hey", "ho", NULL};
	my_str(my_vect2str(vector));
	my_char('\n');
	
	my_str("Testing str2vect\n");
	char* x = "hey there   all of you all";
	char** xx = my_str2vect(x);
	for(int c = 0; c < 6; c++){
		my_str(xx[c]);
		my_char('\n');
	}
	char* y = NULL;
	my_str2vect(y);
	my_str("trying\n");
	char z[35] = "hello";
	char** yy = my_str2vect(&(z[0]));
	for(int b = 0; b < 1; b++){
		my_str(yy[b]);
		my_char('\n');
	}
	//my_str(my_vect2str(my_str2vect(x)));

	//VARS
	char str[] = {'H','E','L','L','O','\0'};
	char str2[] = {'B', 'O', 'B', '\0'};
	char str3[] = {'H','E','\0'};
	char str4[] = {'H','E','L','L','O','\0'};

	int maxneg = -2147483648;
//	int maxpos =  429496729;

	//MYSTR
	my_str("MYSTR\n----------------------------------------------\n");
	my_str(NULL);								my_str("\t|\tNULL\n");
	my_str("");								my_str("\t|\tEmpty String\n");
	my_str("Hello");							my_str("\t|\tHello\n");

	//MYINT
	my_str("\nMYINT\n----------------------------------------------\n");
	my_int(-1); 								my_str("\t|\t-1\n");
	my_int(-156); 								my_str("\t|\t-156\n");
	my_int(0);								my_str("\t|\t0\n");
	my_int(3);								my_str("\t|\t3\n");
	my_int(30);								my_str("\t|\t30\n");
	my_int(maxneg);								my_str("\t|\tMax Neg\n");

	//MYNUMBASE
	my_str("\nMYNUMBASE\n----------------------------------------------\n");
	my_num_base(17, NULL);						my_str("\t|\tNULL\n");
	my_num_base(17, "");						my_str("\t|\tEmpty Set\n ");
	my_num_base(5, "A");						my_str("\t|\tSingle Char - \"AAAAA\"\n ");
	my_num_base(-5, "A");						my_str("\t|\tSingle Char Neg - \"-AAAAA\"\n ");
	my_num_base(0, "01");						my_str("\t|\tZero - \"0\"\n ");
	my_num_base(4, "012345");					my_str("\t|\tSingle Digit - \"4\"\n ");
	my_num_base(18, "01");						my_str("\t|\tDouble Digit - \"10010\"\n ");
	my_num_base(-7, "0123456789ABCDEF");		my_str("\t|\tSingle Digit Negative - \"-7\"\n");
	my_num_base(-195, "0123456789ABCDEF");		my_str("\t|\tDouble Digit Negative - \"-C3\"\n");
	my_num_base(maxneg, "0123456789");			my_str("\t|\tTest Max Negative - \""); my_int(maxneg); my_str("\"\n\n");

	//ALPHA -- DIGITS
	my_str("\nALPHA -- DIGITS\n----------------------------------------------\n");
	my_alpha();									my_str("\t|\tAlpha - ABCDEFGHIJKLMNOPQRSTUVWXYZ\n");
	my_digits();								my_str("\t|\tDigits - 0123456789\n");

	//STRLEN
	my_str("\nMYSTRLEN\n----------------------------------------------\n");
	my_int(my_strlen(NULL));					my_str("\t|\tNULL - \"-1\"\n");
	my_int(my_strlen(""));						my_str("\t|\tEmpty String - \"0\"\n");
	my_int(my_strlen("Hello"));					my_str("\t|\tRegular String - \"5\"\n");

	//REVSTR
	my_str("\nMYREVSTR\n----------------------------------------------\n");
	my_int(my_revstr(NULL));					my_str("\t|\tNULL - \"-1\"\n");
	my_int(my_revstr(""));						my_str("\t|\tEmpty String - \"0\"\n");
	my_int(my_revstr(str3));						my_str("\t|\tRegular String Return - \"5\"\n");
	my_str(str3);							my_str("\t|\tRegular String Changed - \"OLLEH\"\n");
	
	//STRINDEX
	my_str("MYSTRINDEX\n----------------------------------------------\n");
	if(my_strindex(NULL, 'a') == -1) my_char('X');			my_str("\t|\tNull Pointer\n");
	if(my_strindex("", 'a') == -1) my_char('X');			my_str("\t|\tEmpty String\n");
	if(my_strindex(str, 'a') == -1) my_char('X');			my_str("\t|\tNot Found in String\n");
	my_int(my_strindex(str, 'L'));					my_str("\t|\tFound in String - \"1\"\n");

	//STRFIND
	my_str("\nMYSTRFIND\n----------------------------------------------\n");
	my_strfind(str, 'a') == NULL ? my_str("Not Found") : my_str("Something's wrong");	my_str("\t|\tNot found\n");
	my_str(my_strfind(str, 'H')); 						my_str("\t|\tFirst index\n");
	my_str(my_strfind(str, 'O'));						my_str("\t|\tLast index\n");
	my_str(my_strfind(str, 'L'));						my_str("\t|\tMiddle -- from first l\n");
	
	//STRRFIND
	my_str("\nMYSTRRFIND\n----------------------------------------------\n");
	my_strrfind(str, 'a') == NULL ? my_str("Not Found") : my_str("Something's wrong");	my_str("\t|\tNot found\n");
	my_str(my_strrfind(str, 'H')); 						my_str("\t|\tFirst index\n");
	my_str(my_strrfind(str, 'O'));						my_str("\t|\tLast index\n");
	my_str(my_strrfind(str, 'L'));						my_str("\t|\tMiddle -- from second L\n");

	//STRCMP
	my_str("\nMYSTRCMP\n----------------------------------------------\n");
	my_strcmp(NULL, "BILL") == -1 ? my_str("good") : my_str("bad");		my_str("\t|\ta is NULL\n");
	my_strcmp("BILL", NULL) == 1 ? my_str("good") : my_str("bad");		my_str("\t|\tb is NULL\n");
	my_strcmp(NULL, NULL) == 0 ? my_str("good") : my_str("bad");		my_str("\t|\tboth are NULL\n");
	my_strcmp("BILL", "JIM") == 1 ? my_str("good") : my_str("bad");		my_str("\t|\ta is greater\n");
	my_strcmp("BILL", "BILL") == 0 ? my_str("good") : my_str("bad");		my_str("\t|\tsame\n");
	my_strcmp("cd", "fa") == 0 ? my_str("good") : my_str("bad");		my_str("\t|\t fa and cd\n");

	//STRNCMP
	my_str("\nMYSTRNCMP\n----------------------------------------------\n");
    char* a = "hello";
    char* b = "world";
    char* new = my_strnconcat(a, b, 3);
    //my_int(my_strcmp(new, "helloworld");my_char('\n');
    assert(my_strcmp(new, "hellowor") == 0);
    char* new2 = my_strnconcat("hello", NULL, 10);
    assert(my_strcmp(new2, "hello") == 0);
    char* new3 = my_strnconcat(NULL, "hello", 10);
    assert(my_strcmp(new3, "hello") == 0);
    char* new4 = my_strnconcat(NULL, NULL, 10);
    assert(my_strcmp(new4, "") == 0);
	my_strncmp(NULL, "BILL", 5) == -1 ? my_str("good") : my_str("bad");		my_str("\t|\ta is NULL\n");
	my_strncmp("BILL", NULL, 5) == 1 ? my_str("good") : my_str("bad");		my_str("\t|\tb is NULL\n");
	my_strncmp(NULL, NULL, 2) == 0 ? my_str("good") : my_str("bad");		my_str("\t|\tboth are NULL\n");
	my_strncmp("BILL", "JIM", 4) == 1 ? my_str("good") : my_str("bad");		my_str("\t|\ta is greater\n");
	my_strncmp("BILL", "BILLL", 4) == 0 ? my_str("good") : my_str("bad");		my_str("\t|\tsame for n characters\n");
	my_strncmp("BILP", "BILLLPPP", 4) ==  1 ? my_str("good") : my_str("bad");	my_str("\t|\ta greater for n characters\n");
*/
	//STRCPY
	my_str("\nMYSTRCPY\n----------------------------------------------\n");
    //char* a = "aaa";
    //char* b = "bbb";
    char* r = my_strcpy(NULL, NULL);
    assert(my_strcmp(r, NULL) == 0);

    //my_str(my_strcpy(NULL, NULL));		my_str("\t|\tboth are null\n");
	//my_str(my_strcpy(str2,"bob"));		my_str("\t|\tsrc is shorter than dst -- bob\n");
	//my_str(my_strcpy(str,"bob"));		my_str("\t|\tsame length -- bob\n");
	//my_str(my_strcpy(str3,"bob"));		my_str("\t|\tdst is too short -- bo\n");
	//my_str(my_strcpy(NULL,"bob"));		my_str("\t|\tdst is null -- \n");
	//my_str(my_strcpy(str4, NULL));		my_str("\t|\tsrc is null -- \n");

/*
	//STRNCPY
	my_str("\nMYSTRNCPY\n----------------------------------------------\n");
	my_str(my_strncpy(str2,"bob", 3));		my_str("\t|\tsrc is shorter than dst, all src allowed\n");
	my_str(my_strncpy(str2,"jim", 2));		my_str("\t|\tsrc shorted than dist, 2 from src allowed\n");
	my_str(my_strncpy(str3,"bobums", 3));		my_str("\t|\tsrc is long cut by n to -- bob -- by dst to -- bo\n");
	my_str(my_strncpy(NULL,"bob", 3));		my_str("\t|\tdst is null -- \n");
	my_str(my_strncpy(str4, NULL, 2));		my_str("\t|\tsrc is null -- \n");
	my_str(my_strncpy(str4, "bob", 0));		my_str("\t|\tn is zero\n");

	//STRCAT
	my_str("\nMYSTRCAT\n----------------------------------------------\n");
    char apple[20] = {"def"};
    char appl[20] = {"abc"};
    char appapp[20] = {"abcdef"};
    //char res[10] = "ab";
    //char a[10] = "a";
    //char b[10] = "b";
	//char shorty[3] = "hi";
    assert(my_strcat(apple, NULL) == apple);
    assert(my_strcat(NULL, apple) == NULL);
    assert(my_strcat(NULL, NULL) == NULL);
    char* res = my_strcat(appl, apple);
    my_str(res);
    my_char('\n');
    my_int(strcmp(res, appapp));
    //my_str(my_strcat(appl, apple));
    //my_char('\n');
    my_str("\nMYSTRCMP\n---------------------------------------------\n");
    assert(my_strcmp(appl, apple) == -1);
    assert(my_strcmp(apple, appl) == 1);
    assert(my_strcmp(appl, NULL) == 1);
    assert(my_strcmp(NULL, apple) == -1);
    assert(my_strcmp(apple, apple) == 0);
    //assert(my_strcat(a, b) == res);
    //my_str(my_strcat(a, b));
    */
/*
	//STRDUP
	my_str("\nMYSTRDUP\n----------------------------------------------\n");
	my_str(my_strdup("hello"));		my_str("\t|\tduplicating simple string\n");
	my_str(my_strdup(""));		my_str("\t|\tduplicating an empty string\n");
	my_str(my_strdup(NULL));		my_str("\t|\tduplicating a null\n");
	my_str(my_strdup("       /"));		my_str("\t|\tbunch of spaces idk\n");

	
	//STRCONCAT
	my_str("\nMYSTRCONCAT\n----------------------------------------------\n");
	my_str(my_strconcat("hello", "guys"));		my_str("\t|\tconcat simple strings\n");
	my_str(my_strconcat("hello", NULL));		my_str("\t|\tb is NULL\n");
	my_str(my_strconcat(NULL, "guys"));		my_str("\t|\ta is NULL\n");
	my_str(my_strconcat("", "guys"));		my_str("\t|\ta is empty\n");
	my_str(my_strconcat("hello", ""));		my_str("\t|\tb is empty\n");
	my_str(my_strconcat(NULL, NULL));		my_str("\t|\tboth are null\n");
	my_str(my_strconcat("",""));		my_str("\t|\tboth are empty\n");

	//STRNCONCAT
	my_str("\nMYSTRNCONCAT\n----------------------------------------------\n");
    
    my_str(my_strnconcat(NULL, NULL, 4));	my_str("\t|\ttwo nulls\n");
	my_str(my_strnconcat("hello", "guys", 4));	my_str("\t|\tconcat simple strings\n");
	my_str(my_strnconcat("hello", "guys", 3));	my_str("\t|\tsimple strings but a char is cut off of b\n");
	my_str(my_strnconcat(NULL, "guys", 4));		my_str("\t|\ta is NULL, b is full\n");
	my_str(my_strnconcat(NULL, "guys", 2));		my_str("\t|\ta is NULL, two chars off of b\n");
	my_str(my_strnconcat("hello", "", 2));		my_str("\t|\tb is empty\n");
	my_str(my_strnconcat("", "guys", 5));		my_str("\t|\ta is empty, full b allowed\n");
    my_str("TEST IN QUESTION\n");
    my_str(my_strnconcat("aaaaaaaaaa", NULL, 5));		my_str("\t|\ta is a b null\n");
    my_str(my_strnconcat(NULL, "bbbbbbbbbbbb", 0));		my_str("\t|\tb is b a null\n");



	//ATOI
	my_str("\nMYATOI\n----------------------------------------------\n");
	my_int(my_atoi("5")); 			my_str("\t|\t5\n");
	my_int(my_atoi("-5")); 			my_str("\t|\t -5\n");
	my_int(my_atoi("--5")); 		my_str("\t|\t 5\n");
	my_int(my_atoi("a-b54sc7-d")); 		my_str("\t|\t-54\n");
	my_int(my_atoi("abcd")); 		my_str("\t|\t 0\n");
*/	
	return 0;
}
