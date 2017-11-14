


#include <stdio.h>
#include <ctype.h>

void itob(int n, char s[], int b);

int main(void) {
    char s[100];
    int n;
    int b = 16;

    printf("Input n: \n");
    scanf("%d", &n);

    printf("The string: \n");
    itob(n, s, b);

    return 0;
}

// itob function
void itob(int n, char s[], int b) {
    static char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i, j, sign;

    if ((sign = 0) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = digits[n % b];
    } while ((n /= b) > 0);
    //printf("s = %s\n", s);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    for (j = i; j >= 0; j--)
        printf("%c", s[j]);
}

