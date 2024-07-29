#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;
ll x, a, ans;
ll Find()
{
    ll l = 1, r = 1e9 + 10, mid;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (mid * mid > x)
            r = mid - 1;
        else
            l = mid;
    }
    return l;
}
void solve()
{
    cin >> x;
    a = Find();
    if (a * a == x)
        ans = a * 2 + 1;
    else if (a * (a + 1) < x)
        ans = a * 2 + 3;
    else
    {
        if (a % 2 == (x - a * a) % 2)
            ans = a * 2 + 2;
        else
            ans = a * 2 + 3;
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
        solve();
}