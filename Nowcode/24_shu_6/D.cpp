#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n, m;
vector<pair<int, int>> lun, qie, ans;
vector<int> e[N];
int dfn[N], low[N], tot = 0;
stack<int> stk;
int scc[N], cnt = 0;
int f[N];
inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline void tarjan(int x, int fa)
{
    dfn[x] = low[x] = ++tot;
    stk.push(x);
    for (auto y : e[x])
    {
        if (y == fa)
            continue;
        if (!dfn[y])
        {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        }
        else
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        ++cnt;
        int y;
        do
        {
            y = stk.top();
            stk.pop();
            scc[y] = cnt;
        } while (y != x);
    }
}
inline void Zlin()
{
    cin >> n >> m;
    string z;
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        if (z[0] == 'L')
        {
            e[x].push_back(y);
            e[y].push_back(x);
            lun.push_back({x, y});
        }
        else
            qie.push_back({x, y});
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, 0);
    for (auto [x, y] : lun)
        if (scc[x] == scc[y])
            ans.push_back({x, y});
    int check = cnt;
    for (int i = 1; i <= cnt; i++)
        f[i] = i;
    for (auto [x, y] : qie)
    {
        int l = find(scc[x]), r = find(scc[y]);
        if (l != r)
        {
            --check;
            f[l] = r;
            ans.push_back({x, y});
        }
    }
    if (check != 1)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}