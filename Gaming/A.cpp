#include "bits/stdc++.h"
using namespace std;

using ll = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, ans, cnt, l, r;
int a[500010]{};
ll sum[500010]{}, f[500010]{}, len[500010]{};

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y)
{
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = a[i];
        f[i] = i;
        len[i] = 1;
    }
    for (int i = 1; i <= n;)
    {
    }
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