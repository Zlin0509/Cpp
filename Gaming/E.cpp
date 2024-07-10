#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n, ans = 0;
int a[200010]{};

void solve()
{
    cin >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ans += a[i];
    }
    ans -= a[n];
    bool check = false;
    for (int i = 1; i < n; i++)
    {
        if (a[i])
        {
            check = true;
        }
        if (!a[i] && check)
            ++ans;
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