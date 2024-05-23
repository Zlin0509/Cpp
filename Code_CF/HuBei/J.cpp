#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

const ll MOD = 998244353;

ll qpower(ll a, ll b)
{
    ll ans = 1;
    for (; b > 0; b >>= 1, a = a * a % MOD)
        if (b & 1)
            ans = ans * a % MOD;
    return ans;
}

void solve()
{
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        sum += x;
    }
    cout << sum % MOD * qpower(n, MOD - 2) % MOD << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}