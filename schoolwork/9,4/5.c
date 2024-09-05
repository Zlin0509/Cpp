#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, arr[111], i;
    scanf("%d", &n);
    for (i = n - 1; i >= 0; i--)
        scanf("%d", &arr[i]);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
}