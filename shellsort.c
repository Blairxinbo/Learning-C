/*this code can print the whole process and one can check the value of i,j and gap every for loop*/

#include <stdio.h>

void shell_sort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
    {
        printf ("gap = %d\n", gap);
        for (i = gap; i < n; i++)
        {
            printf ("gap = %d,i = %d\n",gap, i);
            for (j = i-gap; j >= 0 && v[j]>v[j+gap]; j-=gap)
            {
                printf("gap = %d,i = %d, j = %d: v[%d] <-> v[%d]\n", gap, i, j, j, j + gap);
                    temp = v[j];
                    v[j] = v[j + gap];
                    v[j + gap] = temp;
            }
        }
    }
}
int main()
{
    int i;
    int v[] = {5, 10, 18, 3, 6, 12, 7, 9, 5};
    shell_sort(v, 9);
    for (i = 0; i < 9; i++)
    {
        printf (" %d ", v[i]);
    }
    return 0;
}
