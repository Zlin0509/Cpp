#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = INT_MAX;
    if (n & 1)
    {
        int n1 = abs(a[n - 1] - b[n / 2]), n2 = abs(b[n - 1] - a[n / 2]);
        for (int i = 0; i < n / 2; i++)
        {
            n1 = min(n1, abs(a[i + 1] - b[i + 1 + n / 2]));
            n1 = min(n1, abs(b[i] - a[i + 1 + n / 2]));
        }
        for (int i = 0; i < n / 2; i++)
        {
            n2 = min(n2, abs(a[i] - b[i + n / 2]));
            n2 = min(n2, abs(b[i] - a[i + 1 + n / 2]));
        }
        cout << max(n1, n2) << '\n';
        return;
    }
    for (int i = 0; i < n / 2; i++)
    {
        ans = min(ans, abs(a[i + n / 2] - b[i]));
        ans = min(ans, abs(b[i + n / 2] - a[i]));
    }
    cout << ans << '\n';
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