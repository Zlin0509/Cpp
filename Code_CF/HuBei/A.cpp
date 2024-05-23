#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve()
{
    ll x, y;
    cin >> x >> y;
    ll z = x / gcd(x, y);
    z *= y / gcd(x, y);
    cout << 1 << ' ' << z << '\n';
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