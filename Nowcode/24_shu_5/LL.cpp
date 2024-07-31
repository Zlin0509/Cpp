#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int a[N];
int n;
long long mo = 998244353;
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= 500; i++)
    {
        for (int j = n; j > 1; j--)
        {
            if (a[j - 1] < a[j] && a[j] != 0)
            {
                a[j]--;
                a[j - 1]++;
            }
        }
    }
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * a[i] % mo;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        Zlin();
    }
    return 0;
}