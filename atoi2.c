/*using switch to rewrite the atoi function*/

#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

main(){
    char s[] = " -6h757jdk";

    printf("%d\n", atoi(s));

}

int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = n * 10 + (s[i] - '0');
    return sign * n;
}
