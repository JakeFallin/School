/*
* Pre: Receives a number as a string
* Post: Returns the number translated into an integer
*/

int my_atoi(char *s)
{
    int r;
    char mod;

    r = 0;
    mod = 1;

    while (*s) 
    {
        if(*s == '-')
            mod *= -1;
        else if(*s == '+')
            ;
        else
            r = (r*10) + (*s) - '0';
        s++;
        
    }

    return r * mod;
}