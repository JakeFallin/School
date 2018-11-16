/*
Pre: Nothing
Post: Prints out all of the digits from 0-9
*/

void my_digits()
{
    char c = '0';
    while(c <= '9')
    {
        my_char(c);
        c++;
    }
}