//copy char t to char s

#include <stdio.h>

int escape(char s[], char t[]);

int main() {

    char t[] = "h\nug\toejf";
    char s[50];
    escape(s, t);
    printf("%s\n", s);

}

int escape(char s[], char t[]) {
    int i, j;

    for (i = 0; i < 50; i++) {
        for (j = 0; t[j] != '\0'; j++) {
            switch (t[j]) {
                case '\n':
                    s[i++] = '\\';
                    s[i++] = 'n';
                    break;
                case '\t':
                    s[i++] = '\\';
                    s[i++] = 't';
                    break;
                default:
                    s[i++] = t[j];
            }
        }
    }
}
