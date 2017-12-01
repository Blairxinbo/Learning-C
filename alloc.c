#define ALLOCSIZE 1000;

static char allocbuf[ALLOSIZE;
static char *allocp = allocbuf;

char *alloc(int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
         allocp += n;
         return allocp - n;
    }else
        return 0;
}
