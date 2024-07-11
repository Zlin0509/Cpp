#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n, ans = 0;
    int a[12]{};
    a[11] = 1;
    cin >> n;
    for (int i = 1, l, r; i <= n; i++)
    {
        cin >> l >> r;
        a[r] = max(a[r], l);
    }
    bool check = false;
    for (int i = 1; i <= 11; i++)
    {
        ans += a[i];
        if (!a[i])
            check = true;
        if (check && a[i])
        {
            cout << "MOREPROBLEMS" << '\n';
            return;
        }
    }
    cout << ans - 1 << '\n';
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