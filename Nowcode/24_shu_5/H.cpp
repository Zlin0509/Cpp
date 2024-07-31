#include "bits/stdc++.h"
using namespace std;
const int N = 1000;
int n, m, dep[N], used[N], ans;
vector<int> e[N];
inline void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    ans = max(ans, dep[u]);
    for (auto v : e[u])
        ++used[v];
    for (auto v : e[u])
        if (v != fa && used[v] == 1)
            dfs(v, u);
    for (auto v : e[u])
        --used[v];
}
inline void Zlin()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; i++)
    {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    // dfs(2, 0);
    for (int i = 1; i <= n; i++)
    {
        memset(dep, 0, sizeof dep);
        ++used[i];
        dfs(i, 0);
        --used[i];
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}