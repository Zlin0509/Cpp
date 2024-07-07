#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int head[310]{};
int vis[310]{};
int num[310]{}; // 邻接矩阵;
long long dis[301][301]{}, h[310]{};
const long long INF = 1e9;
int M[1000010]{};
int ans[1000010]{};

struct edge
{
    int to, next;
    long long w;
} e[2010]{};
struct node
{
    long long dis;
    int pos;
    bool operator<(const node &x) const
    {
        return x.dis < dis;
    }
};
inline void add_edge(int u, int v, int w)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].w = w;
    e[cnt].next = head[u];
    head[u] = cnt;
}
priority_queue<node> q;
inline void dijkstra(int s)
{
    for (int i = 1; i <= n; i++)
        dis[s][i] = INF, vis[i] = 0;
    q.push({0, s});
    dis[s][s] = 0;
    int u;
    while (!q.empty())
    {
        u = q.top().pos;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int y = e[i].to;
            long long d = e[i].w;
            if (dis[s][y] > dis[s][u] + d)
            {
                dis[s][y] = dis[s][u] + d;
                if (!vis[y])
                    q.push({dis[s][y], y});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char c;
        for (int j = 1; j <= n; j++)
        {
            cin >> c;
            if (c == '1')
                add_edge(i, j, 1);
        }
    }

    for (int i = 1; i <= n; i++)
        dijkstra(i);

    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> M[i];
    int l = 1, r = 2, cnt = 1;
    ans[1] = M[1];
    while (l <= m && r <= m)
    {
        if (dis[M[l]][M[r]] < r - l)
            l = r - 1, --r, ans[++cnt] = M[l];
        ++r;
    }
    ans[++cnt] = M[m];
    cout << cnt << '\n';
    for (int i = 1; i <= cnt; i++)
        cout << ans[i] << ' ';
}