#include "stdio.h"
int main()
{
    int all[20] = {2, 4, 3, 5, 8};
    int n = 5;
    double ave = 0;
    for (int i = 0; i < n; i++)
        ave += all[i];
    printf("%lf", ave / n);
}