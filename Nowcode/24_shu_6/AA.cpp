#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
struct edge
{
    int to, next, val;
} e[N << 1];
int tot, head[N], dep[N], a[N], b[N];
double ans[N];
inline void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}
inline void prework(int u, int fa, int d)
{
    a[u] += a[fa], b[u] += b[fa];
    dep[u] = d;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != fa)
        {
            e[i].val ? a[v]++ : b[v]++;
            prework(v, u, d + 1);
        }
    }
    if (a[u])
        ans[u] = (double)a[u] / (a[u] + b[u]);
    else
        ans[u] = 0;
}
inline void dfs(int u, int fa)
{
    int ff = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v == fa)
            continue;
        if (!ff)
            ff = v;

        dfs(v, u);
        if (dep[u] % 2 == 1 && ans[v] > ans[ff])
            ff = v;
        if (dep[u] % 2 == 0 && ans[v] < ans[ff])
            ff = v;
    }
    if (ff)
    {
        if (u != 1)
            ans[u] = min(ans[u], ans[ff]);
        else
            ans[u] = ans[ff];
    }
}
inline void Zlin()
{
    tot = 0;
    cin >> n;
    for (int i = 1, u, v, w; i < n; i++)
    {
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    prework(1, 0, 1);
    dfs(1, 0);
    printf("%.12lf\n", ans[1]);
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = head[i] = ans[i] = 0;
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
}