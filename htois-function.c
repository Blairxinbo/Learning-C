#include <stdio.h>

int htoi(char s[]);

main()
{
    int n;
    char s[] = "0xFF23";
    n = htoi(s);
    printf("n is %d", n);

}

int htoi(char s[])
{
    int i,n,j;
    n=0;
    if(s[0]!='0'&&(s[1]!='x'||s[1]!='X')){
        printf("input wrong\n");
        return 0;
    }


    for(i=2;(s[i]>='0'&&s[i]<='9')||(s[i]>='a'&&s[i]<='f')||(s[i]>='A'&&s[i]<='F');++i){
        if(s[i]>='0'&&s[i]<='9')
            j=s[i]-'0';
        else if(s[i]>='a'&&s[i]<='f')
            j=s[i]-'a'+10;
        else
            j=s[i]-'A'+10;
        n=16*n+j;
    }
    return n;
}

