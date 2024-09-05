#include "stdio.h"
int main()
{
    int len1, len2;
    scanf("%d %d", &len1, &len2);
    char a[len1 + 1], b[len2 + 1];
    scanf("%s", &a);
    scanf("%s", &b);
    int check;
    for (int i = 0; i < len1 - len2; i++)
    {
        check = 1;
        for (int j = 0; j < len2; j++)
        {
            if (a[i + j] != a[j])
            {
                check = 0;
                break;
            }
        }
        if (check)
            break;
    }
    printf("%d", check);
}