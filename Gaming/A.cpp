#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
ll dp[4][100010]{}, ans = 1e18;
ll c[4][100010]{};
int n, tot = 0, head[200010];
int d[100010]{};
int aa[100010]{};
vi z;
struct Edge
{
    int to, next;
} e[200010]{};
void add(int u, int v)
{
    ++tot;
    e[tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
void dfs(int u, int fa)
{
    z.push_back(u);
    for (int i = head[u]; i; i = e[i].next)
    {
        if (e[i].to != fa)
        {
            dfs(e[i].to, u);
        }
    }
}

void cal(int s, int ss, int sss)
{
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            for (int q = 1; q <= 3; q++)
                if (i != j && j != q && i != q)
                    dp[i][s] = min(dp[i][s], dp[q][sss] + c[j][ss] + c[i][s]);
}

void check(int s, int ss, int sss)
{
    int i = aa[s];
    for (int j = 1; j <= 3; j++)
        for (int q = 1; q <= 3; q++)
            if (i != j && j != q && i != q && dp[i][s] == dp[q][sss] + c[j][ss] + c[i][s])
            {
                aa[ss] = j;
                aa[sss] = q;
                return;
            }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= n; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
    {
        dp[1][i] = dp[2][i] = dp[3][i] = 1e16;
    }
    for (int i = 1, u, v; i < n; i++)
    {
        cin >> u >> v;
        add(u, v), add(v, u);
        ++d[u];
        ++d[v];
    }
    for (int i = 1; i <= n; i++)
        if (d[i] > 2)
        {
            cout << -1;
            return 0;
        }
    for (int i = 1; i <= n; i++)
        if (d[i] == 1)
        {
            dfs(i, i);
            break;
        }
    for (int i = 1; i <= 3; i++)
        dp[i][z[0]] = c[i][z[0]];
    int l = 2;
    for (; l < n; l += 2)
    {
        cal(z[l], z[l - 1], z[l - 2]);
    }
    for (int i = 1; i <= 3; i++)
        ans = min(ans, dp[i][z[l]]);
    for (int i = 1; i <= 3; i++)
        if (dp[i][z[l]] == ans)
            aa[z[l]] = i;
    for (; l >= 2; l -= 2)
        check(z[l], z[l - 1], z[l - 2]);
    for (int i = 1; i <= 3; i++)
    {
        if (i != aa[l] && i != aa[l - 1])
        {
            ans += c[i][n - 1];
            aa[n - 1] = i;
            break;
        }
    }
    // if (n % 2)
    // {
    //     for (int i = 1; i <= 3; i++)
    //     {
    //         if (i != aa[l] && i != aa[l - 1])
    //         {
    //             ans += c[i][n - 1];
    //             aa[n - 1] = i;
    //             break;
    //         }
    //     }
    //     for (int i = 1; i <= n; i++)
    //     {
    //         dp[1][i] = dp[2][i] = dp[3][i] = 1e16;
    //     }
    //     for (int i = 1; i <= 3; i++)
    //         dp[i][z[1]] = c[i][z[1]];
    //     l = 3;
    //     for (; l < n; l += 2)
    //     {
    //         cal(z[l], z[l - 1], z[l - 2]);
    //     }
    //     ll ans2 = 1e18;
    //     for (int i = 1; i <= 3; i++)
    //         ans2 = min(ans2, dp[i][l]);
    //     for (int i = 1; i <= 3; i++)
    //         if (dp[i][z[l]] == ans)
    //             aa[z[l]] = i;
    //     for (; l >= 3; l -= 2)
    //         check(z[l], z[l - 1], z[l - 2]);
    //     for (int i = 1; i <= 3; i++)
    //         if (i != aa[z[1]] && i != aa[z[2]])
    //         {
    //             ans2 += c[i][z[0]];
    //             aa[z[0]] = i;
    //             break;
    //         }
    //     if (ans2 < ans)
    //     {
    //         for (int i = 1; i <= n; i++)
    //         {
    //             dp[1][i] = dp[2][i] = dp[3][i] = 1e16;
    //         }
    //         for (int i = 1; i <= 3; i++)
    //             dp[i][z[0]] = c[i][z[0]];
    //         l = 2;
    //         for (; l < n; l += 2)
    //         {
    //             cal(z[l], z[l - 1], z[l - 2]);
    //         }
    //         for (int i = 1; i <= 3; i++)
    //             ans = min(ans, dp[i][z[l]]);
    //         for (int i = 1; i <= 3; i++)
    //             if (dp[i][z[l]] == ans)
    //                 aa[z[l]] = i;
    //         for (; l >= 2; l -= 2)
    //             check(z[l], z[l - 1], z[l - 2]);
    //         for (int i = 1; i <= 3; i++)
    //         {
    //             if (i != aa[l] && i != aa[l - 1])
    //             {
    //                 ans += c[i][n - 1];
    //                 aa[n - 1] = i;
    //                 break;
    //             }
    //         }
    //     }
    // }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << aa[i] << ' ';
}