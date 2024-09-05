#include "stdio.h"
int main()
{
    int n;
    scanf("%d", &n);
    int m;
    int a[n];
    int l;
    for (l = 0; l < n; l++)
        scanf("%d", &a[l]);
    int i, j;
    for (i = 1; i < n; i++)
    {
        int t = a[i];
        for (j = i - 1; a[j] > t && j >= 0; j--)
            a[j + 1] = a[j];
        a[j + 1] = t;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}