/* Library for simple functions with chars, ints, and strings.
Includes functions to print inputs and perform simple string operations */

#include <stdlib.h>
#include <unistd.h>

#ifndef _MY_H_
#define _MY_H_

#ifndef NULL
#define NULL ((void*)0)
#endif

int my_atoi(char *);

char *my_vect2str(char**);
char **my_str2vect(char*);
void my_printvect(char **);
char *my_stripbuffer(char *);

void my_char(char);
void my_str(char*);
void my_int(int);
void my_num_base(int, char*);

void my_alpha();
void my_digits();

int my_strindex(char*, char);
int my_strrindex(char*, char);

int my_strlen(char*);
int my_revstr(char*);

char *my_find(char*, char);
char *my_rfind(char*, char);

char *my_strcat(char*, char*);

int my_strcmp(char*, char*);
int my_strncmp(char*, char*, int);

char *my_strconcat(char*, char*);
char *my_strnconcat(char*, char*, int);
char *my_stdstrnconcat(char*, char*, int);

char *my_strcpy(char*, char*);
char *my_strncpy(char*, char*, int);

void *xmalloc(int);

char *my_strdup(char*);

#endif