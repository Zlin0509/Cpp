#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
int a[200010]{};
int f[200010]{}, num[200010]{};
int ss[200010]{};
struct Edge
{
    int to, next, val;
} e[400010]{};
int head[400010]{}, tot = 0;
void add(int u, int v, int val)
{
    ++tot;
    e[tot].to = v;
    e[tot].val = val;
    e[tot].next = head[u];
    head[u] = tot;
}
int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    if (fx > fy)
        swap(fx, fy);
    f[fy] = fx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1, u, v, val; i < n; i++)
    {
        cin >> u >> v >> val;
        add(u, v, val), add(v, u, val);
        if (val == 1)
            ss[u] = ss[v] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j; j = e[j].next)
        {
            
        }
    }
}