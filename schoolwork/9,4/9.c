#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(void)
{
    srand(time(NULL));
    int j, s = 0;
    FILE *fp = NULL;
    fp = fopen("xxxxxxxxx", "a");
    for (int i = 0; i < 10; i++)
    {
        j = rand() % 100;
        fprintf(fp, "%5d", j);
    }
    fclose(fp);
    fp = fopen("xxxxxxxx", "r");
    double ave = 0;
    while (fscanf(fp, "%5d", j) != EOF)
        ave += j;
    printf("%ld\n", ave / 10);
    return 0;
}