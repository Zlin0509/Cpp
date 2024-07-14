#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, k, used[200010]{}, ans = 0, x;
struct ss
{
    int to, next, val;
} e[200010]{};
int tot = 0, head[200010]{};

void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    e[tot].val = val;
    head[u] = tot;
}

bool dfs(int u, int fa)
{
    bool check = false, cc;
    for (int i = head[u]; i; i = e[i].next)
        if (e[i].to != fa)
        {
            cc = dfs(e[i].to, u);
            if (cc)
                check = true;
        }
    if (check)
        ++used[u];
    if (used[u])
        return 1;
    return check;
}

void solve()
{
    cin >> n >> k;
    for (int i = 1, u, v, val; i < n; i++)
    {
        cin >> u >> v >> val;
        add(u, v, val);
        add(v, u, val);
    }
    for (int i = 1; i <= k; i++)
    {
        cin >> x;
        ++used[x];
    }
    dfs(x, x);
    for (int i = 1; i <= n; i++)
        if (used[i])
            ++ans;
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}