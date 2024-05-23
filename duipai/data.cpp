#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
   srand(time(0));
    //这是一个生成随机数随机种子，需要用到 ctime 库
    int n=rand()+1,k=rand()+1;
    printf("%d %d\n", n,k);
    //这样就生成了2个随机数
    for (int i = 0; i < n; i++)
    {
        printf("%c",'a' + rand() % 26); //随机生成字母，这里采用对26取余数，得到的余数在0~25之间
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c",'a' + rand() % 26); //随机生成字母，这里采用对26取余数，得到的余数在0~25之间
    }
    return 0;
}