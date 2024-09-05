#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int f[N];
int n, m;
struct edge
{
    int to, next, val;
} e[N << 1];
int tot = 0, head[N];
inline void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    e[tot].val = val;
    head[u] = tot;
}
inline int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }
inline void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    f[fy] = fx;
}
inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        string x;
        cin >> u >> v >> x;
        int l, r;
        x == "Lun" ? w = 1 : w = 0;
        add(u, v, w), add(v, u, w);
        if (f[u] != u)
        {
            l = u;
            r = v;
        }
        else
        {
            r = u;
            l = v;
        }
        merge(l, r);
    }
    for(int i)
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}