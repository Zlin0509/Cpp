#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m, l, r, l1, r1;
int a[200010]{};
ll sum[200010]{}, ans = 0;
priority_queue<int, vi, greater<int>> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], sum[i] = sum[i - 1] + a[i];
    for (int i = 1, x; i <= m; i++)
    {
        cin >> x, b.push(x + 100);
    }
    r = b.top(), b.pop();
    if (r % 100)
        r1 = r / 100;
    else
        r1 = r / 100 - 1;
    ans = sum[min(r1, n)];
    while (!b.empty())
    {
        l = r;
        r = b.top(), b.pop();
        if (r > n * 100)
            break;
        l1 = l / 100 + 1;
        r1 = (r % 100 ? r / 100 : r / 100 - 1);
        for (int i = l1, xx, yy, yy1; i <= r1; i++)
        {
            xx = i * 100;
            yy1 = xx * 2 - l + r;
            yy1 = min(yy1, r * 2);
            if (yy1 % 200)
                yy = yy1 / 200;
            else
                yy = yy1 / 200 - 1;
            ans = max(ans, sum[yy] - sum[i - 1]);
        }
    }
    r1 = r / 100 + 1;
    // cout << l << ' ' << r << '\n';
    if (r1 < n + 1)
        ans = max(ans, sum[n] - sum[r1 - 1]);
    else
    {
        l1 = l / 100 + 1;
        r1 = n;
        for (int i = l1, xx, yy, yy1; i <= r1; i++)
        {
            xx = i * 100;
            yy1 = xx * 2 - l + r;
            yy1 = min(yy1, r * 2);
            if (yy1 % 200)
                yy = yy1 / 200;
            else
                yy = yy1 / 200 - 1;
            yy = min(yy, n);
            ans = max(ans, sum[yy] - sum[i - 1]);
        }
    }
    cout << ans;
}