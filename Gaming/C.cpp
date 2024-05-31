#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m;
int a[200010]{}, b[200010]{};
int c[200010]{};
ll sum, num, t1, t2, ans;

void solve()
{
    sum = 0, num = 0, t1 = -1, t2 = -1;
    cin >> n >> m;
    int l, r;
    for (int i = 0; i < n + m + 1; i++)
        cin >> a[i];
    for (int i = 0; i < n + m + 1; i++)
        cin >> b[i];
    for (int i = 0; i < n + m; i++)
    {
        if (a[i] > b[i])
        {
            if (t1 == n)
                l = i;
            if (t1 < n)
            {
                sum += a[i];
                c[i] = 1;
            }
            else
                sum += b[i], c[i] = -1;
            ++t1;
        }
        else
        {
            if (t2 == m)
                r = i;
            if (t2 < m)
            {
                sum += b[i];
                c[i] = 1;
            }
            else
                sum += a[i], c[i] = -1;
            ++t2;
        }
    }
    for (int i = 0; i < n + m; i++)
    {
        if (c[i] == 1)
        {
            ans = sum - max(a[i], b[i]);
            if (a[i] > b[i])
            {
                ans += a[l] - b[l];
            }
            else
            {
                ans += b[r] - a[r];
            }
        }
        else
        {
            ans = sum - min(a[i], b[i]);
            if (a[i] > b[i])
            {
                ans += b[n];
            }
            else
            {
                ans += a[n];
            }
        }
        cout << ans << ' ';
    }
    cout << sum << " ";
    cout << '\n';
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