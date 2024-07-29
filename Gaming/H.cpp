#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int n, l;
ll a[200010]{};
ll aa;
ll qGCD(ll a, ll b)
{
    ll az = __builtin_ctzll(a), bz = __builtin_ctzll(b); // 如果数据ll，用函数ctzll
    ll z = min(az, bz), dif;
    b >>= bz;
    while (a)
    {
        a >>= az;
        dif = llabs(b - a);
        az = __builtin_ctzll(dif);
        if (a < b)
            b = a;
        a = dif;
    }
    return b << z;
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    aa = 0;
    for (l = 2; l <= n; l++)
        if (a[l] - a[l - 1])
        {
            aa = a[l] - a[l - 1];
            break;
        }
    for (int i = l; i <= n; i++)
    {
        if (a[i] - a[i - 1])
            aa = qGCD(aa, a[i] - a[i - 1]);
    }
    cout << aa << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}