//use pointer to achive strend function

#include <stdio.h>

int strend(char *s, char *t);

int main() {

}


int strend(char *s, char *t) {
    char *sp = s;
    char *tp = t;

    for (; *s; s++);
    for (; *t; t++);
    for (; *s == *t; s--, t--) {
        if (t == tp || s == sp)
            break;
    }

    if (t == tp && *s != '\0' && *s == *t) {
        return 1;
    } else
        return 0;
}

