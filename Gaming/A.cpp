#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve()
{
    ll l, r;
    cin >> l >> r;
    ll n = 1, num = 0;
    // while (n <= l)
    //     n *= 2, ++num;
    while (r / n >= 2)
        n *= 2, ++num;
    // cout << n << '\n';
    cout << num << '\n';
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