#include <stdio.h>
int main()
{
    int len;
    scanf("%d", &len);
    char a[len + 1], b[len + 1];
    scanf("%s", &a);
    int i = 0;
    for (; i < len; i++)
        b[i] = a[i];
    b[i] = '\0';
    printf("%s", b);
    return 0;
}
