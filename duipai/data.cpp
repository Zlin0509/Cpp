#include <cstdio>
#include <cstdlib>
#include <ctime>
int main()
{
   srand(time(0));
    //����һ�����������������ӣ���Ҫ�õ� ctime ��
    int n=rand()+1,k=rand()+1;
    printf("%d %d\n", n,k);
    //������������2�������
    for (int i = 0; i < n; i++)
    {
        printf("%c",'a' + rand() % 26); //���������ĸ��������ö�26ȡ�������õ���������0~25֮��
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c",'a' + rand() % 26); //���������ĸ��������ö�26ȡ�������õ���������0~25֮��
    }
    return 0;
}