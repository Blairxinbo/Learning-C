/*delete the char of s2 from the char of s1 if s2 = s1*/

void squeeze(char s1[], char s2[])
{
        int i,j,n;
        for (i=n=0; s1[i] != '\0'; i++)
           for (j = 0; s2[j] != '\0'; j++)
               if (s1[i] != s2[j])
                   s1[n++] = s1[i];
        s1[n] = '\0';
}
