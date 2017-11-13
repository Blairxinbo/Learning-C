#include <ctype.h>
#include <stdio.h>

void itoa(int n, char s[]);

int main(void) {
    int n;
    char s[100];
    printf("Input n:\n");
    scanf("%d", &n);
    printf("the string : \n");
    itoa(n, s);
    return 0;
}

void itoa(int n, char s[]) {
    int i, j, sign;
    int a;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
        a = n % 10 + '0';
        printf("s = %s\n", s);
        printf("a = %d\n", a);
    } while ((n /= 10) > 0);
    //printf("s = %s\n", s);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    
    for (j = i; j >= 0; j--)
        printf("%c", s[j]);
}
