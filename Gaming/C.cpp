#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m, cnt, ans1 = 1100, ans2, End;
int c[2200]{}, used[2200]{};
queue<int> q;

int tot = 0, head[2200]{};
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

void dfs(int u, int fa, int depth)
{
    if (c[u])
        ans2 = max(ans2, depth);
    for (int i = head[u]; i; i = e[i].next)
        if (used[e[i].to] && e[i].to != fa)
            dfs(e[i].to, u, depth + 1);
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
        add(u, v), add(v, u);
    }
    for (int i = 1, u; i <= n; i++)
    {
        memset(used, 0, sizeof(used));
        cnt = 0;
        q.push(i);
        while (!q.empty())
        {
            u = q.front();
            q.pop();
            if (cnt >= m || used[u])
                continue;
            if (c[u])
                ++cnt, End = u;
            ++used[u];
            for (int j = head[u]; j; j = e[j].next)
                if (!used[e[j].next])
                    q.push(e[j].to);
        }
        ans2 = 0;
        dfs(End, End, 0);
        ans1 = min(ans1, ans2);
    }
    cout << ans1;
}