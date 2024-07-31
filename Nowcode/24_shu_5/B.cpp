#include "bits/stdc++.h"
using namespace std;
int n, m, a, b;
inline void Zlin()
{
    cin >> n >> m >> a >> b;
    if (n > m)
        swap(n, m);
    if (a == 1 && b == 1)
    {
        if (n & 1 && m & 1)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
    else if (a == 1)
    {
        if (n == 1 && m % 2 == 0)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    else if (b == 1)
    {
        if (n <= 3)
        {
            if (n == 2 || (n == 1 && m == 2) || (n == 3 && m % 2 == 0))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            if (n % 2 == 0 || m % 2 == 0)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
    else
    {
        if (n == 1 && m == 2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    while (n--)
        Zlin();
}