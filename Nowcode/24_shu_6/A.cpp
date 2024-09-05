#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
struct edge
{
    int to, next, val;
} e[N << 1];
int tot, head[N], a[N], b[N];
double ans;
inline void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}
vector<int> ee[N];
inline void dfs(int u, int fa, int dep)
{
    int ff = 0;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].to;
        if (v != fa)
        {
            e[i].val ? ++a[v] : ++b[v];
            if (!ff)
                ff = v;
            dfs(v, u, dep + 1);
            if (dep & 1)
            {
                if ((a[v] == a[ff] && b[v] <= b[ff]) || a[v] > a[ff])
                    ff = v;
            }
            else
            {
                if ((b[v] == b[ff] && a[v] <= a[ff]) || b[v] > b[ff])
                    ff = v;
            }
        }
    }
    a[u] += a[ff], b[u] += b[ff];
    ee[u].push_back(ff);
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
    bool check = 0;
    for (int i = head[1]; i; i = e[i].next)
        if (e[i].val)
        {
            check = 1;
            break;
        }
    ans = 1;
    if (check)
    {
        dfs(1, 0, 1);
    }
    else
        ans = 0;
    printf("%.12lf\n", ans);
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = head[i] = 0;
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