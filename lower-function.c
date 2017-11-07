/*transfer a character into a lower case: only for ASCII*/

#include <stdio.h> 
#include <ctype.h>



int lower(int c);

main(void){

     int c;
     c = getchar();
     printf("interger = %d\n", lower(c));
    return 0;
    }



int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}

