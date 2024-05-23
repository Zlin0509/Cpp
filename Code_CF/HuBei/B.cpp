#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
double a[1010]{}, b[1010]{};
double c1, c2, c3;

bool check1(double c1, double c2, double c3)
{
    if (c1 + c2 <= c3 + 0.000005 && c1 + c2 >= c3 - 0.000005)
        return false;
    if (c1 + c3 <= c2 + 0.000005 && c1 + c3 >= c2 - 0.000005)
        return false;
    if (c3 + c2 <= c1 + 0.000005 && c3 + c2 >= c1 - 0.000005)
        return false;
    return true;
}

void solve()
{
    cin >> n;
    double ans = 1e10, p;
    bool check = false;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            for (int q = j + 1; q <= n; q++)
            {
                c1 = sqrt((a[i] - a[j]) * (a[i] - a[j]) + (b[i] - b[j]) * (b[i] - b[j]));
                c2 = sqrt((a[i] - a[q]) * (a[i] - a[q]) + (b[i] - b[q]) * (b[i] - b[q]));
                c3 = sqrt((a[q] - a[j]) * (a[q] - a[j]) + (b[q] - b[j]) * (b[q] - b[j]));
                if (check1(c1, c2, c3))
                {
                    // cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
                    // cout << c1 + c2 << " " << '\n';
                    check = true;
                    p = (c1 + c2 + c3) / 2;
                    // cout << c1 << ' ' << c2 << ' ' << c3 << '\n';
                    ans = min(ans, sqrt(p * (p - c1) * (p - c2) * (p - c3)));
                }
            }
        }
    }
    if (check)
        printf("%lf\n", ans);
    else
        printf("-1\n");
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