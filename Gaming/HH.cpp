#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
ull x, a, b, ans, z, ans2;
void solve()
{
    ans = 1e16;
    cin >> x;
    z = x;
    a = sqrt(x) + 1;
    if (a < 2)
        a = 2;
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
        solve();
}