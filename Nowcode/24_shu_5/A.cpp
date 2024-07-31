#include "bits/stdc++.h"
using namespace std;
const int N = 5e4 + 10;
int n, m, q;
int a[N], ans[N];
int f[N][22];
struct ss
{
    int l, r, id;
    friend bool operator<(const ss &a, const ss &b)
    {
        if (a.r != b.r)
            return a.r < b.r;
        return a.l < b.l;
    }
} e[N];
inline void Zlin()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        char c;
        int ll = 0, rr = 0;
        for (int j = m; j >= 1; j--)
        {
            cin >> c;
            if (c == '1')
                ll = max(ll, j), ++rr;
            a[i] = ll - 1;
            if (rr - 1)
                ++a[i];
        }
    }
    for (int i = 1; i <= q; i++)
        cin >> e[i].l >> e[i].r, e[i].id = i;
    sort(e + 1, e + 1 + q);
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}