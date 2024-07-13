#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const int N = 2e5 + 10;
int a[N] = {0}, b[N] = {0}, c[N];

void solve()
{
    int n, m, l;
    cin >> n >> m >> l;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        int p;
        if (l < y)
            continue;
        p = l - y;
        // cout << p << "\n";
        if (p >= x)
        {
            a[j] = 1;
            b[j] = p + x;
            j++;
        }
        else
        {
            a[j] = x - p;
            b[j] = p + x;
            j++;
        }
    }
    j--;
    sort(a + 1, a + j + 1);
    sort(b + 1, b + j + 1);
    // cout << a[1] << " " << b[1];
    for (int i = 1; i <= j; i++)
    {
        // cout << a[i] << " " << b[i] << "\n";
    }
    for (int i = 0; i < m; i++)
    {
        int p;
        cin >> p;
        int k1, k2;
        k1 = upper_bound(a + 1, a + j + 1, p) - a;
        k2 = upper_bound(b + 1, b + j + 1, p - 1) - b;
        k1--;
        k2--;
        // cout << p << " " << k1 << " " << k2<<"\n";
        cout << k1 - k2 << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt = 1;
    while (ttt--)
        solve();
}