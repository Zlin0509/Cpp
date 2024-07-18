#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n, m, q, ans = 0;
ll c[5010][5010]{};

inline ll quick_pow(ll a, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1)
            res = res * a % q;
        a = a * a % q;
        n >>= 1;
    }
    return res;
}

inline void init()
{
    for (int i = 0; i <= 5001; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % q;
}



void Zlin()
{
    cin >> n >> m >> q;
    init();
    for (int i = 1; i <= n; i++)
    {
        ll z = quick_pow(quick_pow(2, i) - 1, m - 1) * quick_pow(quick_pow(2, n - i), m - 1) % q;
        z = z * c[n][i] % q;
        ans = (ans + z + q) % q;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}