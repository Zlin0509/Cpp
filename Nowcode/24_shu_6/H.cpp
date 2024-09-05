#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;

inline void Zlin()
{
    int sum1 = 0, sum2 = 0;
    string a;
    cin >> a;
    bool flag = true;
    int f = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '3')
            sum1++;
        else
            sum1 = 0;
        if (a[i] != 'U' && a[i] != '5')
            sum2++;
        else
            sum2 = 0;
        if (sum1 >= 10 || sum2 >= 90)
        {
            flag = false;
            break;
        }
        if (a[i] == '5' && f == 1)
        {
            flag = false;
            break;
        }
        else if (a[i] == '5' && f == 0)
            f = 1;
        else if (a[i] == 'U')
            f = 0;
    }
    if (flag == true)
        cout << "valid" << '\n';
    else
        cout << "invalid" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}