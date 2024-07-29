#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const int N = 1e6 + 10;
vll a[N];
ll ans[N];
ll n, m;
ll sum;
void solve()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        a[v].push_back(u);
    }
    for (int i = 2; i <= n; i++)
    {
        ll l = 0, r = i;
        sort(a[i].begin(), a[i].end(), greater<int>());
        for (auto v : a[i])
        {
            if (v == r - 1 && v >= l)
                ++ans[i];
            else
                break;
            r = v;
            l = max(l, v - ans[v]);
        }
    }
    sum = n;
    for (int i = 1; i <= n; i++)
    {
        sum += ans[i];
    }
    cout << sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
}