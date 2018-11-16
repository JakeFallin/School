/*
Test for my_vect2str(char**)
*/

#include "../lib/my.h"

int main(int argc, char **argv)
{
    my_str(my_vect2str(&argv[1]));
}