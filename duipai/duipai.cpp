#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    while (1) //һֱѭ����ֱ���ҵ���һ��������
    {
        system("data.exe");
        system("baoli.exe");
        system("std.exe");
        if (system("fc std.txt baoli.txt")) //�� fc ����1ʱ��˵����ʱ���ݲ�һ��
            break;                          //��һ��������ѭ��
    }
    return 0;
}