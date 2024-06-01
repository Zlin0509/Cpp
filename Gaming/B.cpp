#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll a[10001]{}, b[10001]{};

void solve()
{
    ll n, m;
    cin >> n >> m;
    if (m == 0)
    {
        cout << n << '\n';
        return;
    }
    ll l = max(0ll, n - m), r = n + m;
    int l1 = 64 - __builtin_clzll(l), r1 = 64 - __builtin_clzll(r);
    // cout << l1 << ' ' << r1 << '\n';
    if (l1 < r1 || l == 0)
    {
        cout << (1ll << r1) - 1 << '\n';
        return;
    }
    int x = r1;
    ll z = 0;
    while ((l & (1ll << x)) == (r & (1ll << x)))
    {
        z += (l & (1ll << x));
        --x;
    }
    // cout << x << " " << r1 << '\n';
    cout << z + (1ll << (x + 1)) - 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}