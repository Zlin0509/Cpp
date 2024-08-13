#include "bits/stdc++.h"
using namespace std;
int n, m;
char x[550][550];
int len1, len2;
inline void Zlin()
{
    cin >> n >> m;
    bool x1 = 0, x2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> x[i][j];
            if (x[i][j] == 'x')
            {
                x2 = 1;
                if (!x1)
                    ++len2;
            }
        }
        x1 = len2;
        if (x2)
            ++len1, x2 = 0;
    }
    int z = gcd(len1, len2);
    len1 /= z, len2 /= z;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
            cout << 'x';
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}