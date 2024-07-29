#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 10;
int dep[N], f[N], ans[N];
int n, sum;
inline int find(int x)
{
    if (x == f[x])
        return x;
    int y = find(f[x]);
    dep[x] += dep[f[x]];
    f[x] = y;
    return f[x];
}
inline void merge(int x, int y)
{
    int fx = find(x);
    dep[y] = dep[x] + 1;
    f[y] = fx;
    ans[fx] = max(ans[fx], ans[y] + dep[x] + 1);
}
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i] = i, dep[i] = ans[i] = 0;
    for (int i = 1, a, b, c; i < n; i++)
    {
        cin >> a >> b >> c;
        merge(a, b);
        cout << ans[c] << ' ';
    }
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}