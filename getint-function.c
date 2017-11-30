#include <stdio.h>
#include <ctype.h>

#define SIZE 100;

int n, array[SIZE], getint(int *);

getint(int *);

int getch(void);

void ungetch(int);

int getint(int *pn) {
    int i, c, sign;

    while (isspace(c = getch())) //space escaped
        ;
    if (isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        i = c;
        c = getch();
        if (!isdigit(c)) {
            if (c != EOF)
                ungetch(c);
            ungetch(i);
        }
    }
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
