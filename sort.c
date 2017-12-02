//We can use C to achive a sort funcion for UNIX

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *allocbuf, int nlines); //读入函数

char *alloc(int);

//void strcpy(char *s, char *t);  //copy函数


void writelines(char *lineptr[], int nlines);   //写入函数

void qsort(char *lineptr[], int left, int right); //排序函数

int main() {
    int nlines;
    char allocbuf[ALLOCSIZE];
    char *p = allocbuf;

    if ((nlines = readlines(lineptr, allocbuf, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000

int getlline(char *, int);

int readlines(char *lineptr[], char *allocbuf, int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = allocbuf;
    while ((len = getlline(line, MAXLEN)) > 0)
        if (nlines > maxlines || (allocbuf+ALLOCSIZE-p) < len)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

int getlline(char *s, int lim) {
    int c;
    char *t = s;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

void writelines(char *lineptr[], int nlines) {
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

//void swap(char *v[], int i, int j);

void qsort(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; )
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
