#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;

int n, num;
double ans;
int Sam, l;
ll a[300010]{};

void solve()
{
    num = 3;
    Sam = INT_MAX;
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];    
        if (Sam > a[i])
            Sam = a[i], l = i;
        a[i] += a[i - 1];
    }
    ans = (double)a[n] / n;
    ans = max(ans, (double)a[l + 1] / (l + 1));
    ans = max(ans, (double)(a[n] - a[l - 2]) / (n - l + 2));
    printf("%.020lf\n", ans);
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