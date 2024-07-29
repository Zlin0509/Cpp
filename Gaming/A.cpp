#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const int N = 1e6 + 10;
int fa[N], sizen[N];
inline int find(int u, int a)
{
    if (fa[u] == u)
    {
        return u;
    }
    else
    {
        sizen[u] = max(sizen[u], a + 1);
        sizen[fa[u]] = max(sizen[fa[u]], sizen[u] + 1);
        fa[u] = find(fa[u], a);
    }
}
inline void merge(int x, int y)
{
    int fx = find(x, 0), fy = find(y, 0);
    if (fx == fy)
        return;
    else
    {
        fa[fy] = fx;
        if (fx == x)
            sizen[fx] = max(sizen[fx], sizen[fy] + 1);
        else
        {
            int a = sizen[fy];
            fa[x] = find(x, a);
        }
    }
}
void init()
{
    for (int i = 1; i < N; i++)
        fa[i] = i;
}
void del()
{
    for (int i = 1; i < N; i++)
        sizen[i] = 0;
}
void solve()
{
    init();
    del();
    int n;
    cin >> n;
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        merge(x, y);
        cout << sizen[z] << " ";
        cout << fa[8] << endl;
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}