#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n, d1, d2;
ll a[1000010]{}, b[1000010]{};
double d, ans;
vll x;

void solve()
{
    d1 = -1e16, d2 = 1e16;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] -= d * (i - 1);
    for (int i = 1; i <= n; i++)
        d1 = max(d1, a[i]), d2 = min(d2, a[i]);
    ans = d1 - (d1 + d2) / 2.0;
    d1 = -1e16, d2 = 1e16;
    for (int i = 1; i <= n; i++)
        a[i] += d * (i - 1);
    for (int i = n - 1; i >= 1; i--)
        a[i] -= d * (n - i);
    for (int i = 1; i <= n; i++)
        d1 = max(d1, a[i]), d2 = min(d2, a[i]);
    printf("%.1lf", ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}