#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m, ans = 1000, depth[21000]{}, used[21000]{}, cnt, End, ans2;
int c[21000]{};
int tot = 0, head[21000]{};
struct Edge
{
    int to, next;
} e[2200]{};
void add(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}

queue<int> q;
void dfs(int u, int fa, int dep)
{
    if (c[u] || dep > ans)
        ans2 = max(ans2, dep);
    if (ans2 >= ans)
        return;
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa && used[e[i].to])
            dfs(e[i].to, u, dep + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1, u, z1, z2; i <= n; i++)
    {
        memset(depth, 0, sizeof(depth));
        memset(used, 0, sizeof(used));
        while (!q.empty())
            q.pop();
        c[i] ? cnt = 1 : cnt = 0;
        q.push(i);
        used[i] = 1;
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            if (cnt >= m)
                break;
            for (int i = head[u]; i; i = e[i].next)
            {
                if (!used[e[i].to])
                {
                    ++used[e[i].to];
                    depth[e[i].to] = depth[u] + 1;
                    if (c[e[i].to])
                        ++cnt, End = e[i].to;
                    q.push(e[i].to);
                }
            }
        }
        ans2 = 0;
        dfs(End, End, 0);
        ans = min(ans, ans2);
    }
    cout << ans;
}