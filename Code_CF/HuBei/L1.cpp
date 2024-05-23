#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

const ll N = 1010;
ll x[N], y[N];
int n;

int det(int x1, int y1, int x2, int y2)
{
    return x1 * y2 - y1 * x2;
}

const double eps = 1e-6;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    bool f = 0;
    if (n <= 2)
    {
        cout << -1 << '\n';
        return;
    }
    double ans = 1e18;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                double res = 1.0 * abs(det(x[j] - x[i], y[j] - y[i], x[j] - x[k], y[j] - y[k])) / 2.0;
                if (fabs(res) > eps)
                {
                    f = 1;
                    ans = min(ans, res);
                }
            }
        }
    }
    cout << setprecision(7);
    if (!f)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << ans << '\n';
    }
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