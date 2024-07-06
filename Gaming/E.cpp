#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n, m;
int a[500010]{};

struct ss
{
    int l, r;
    int tag, num;
} T[21][600010]{};

void cal(int i, int j)
{
    if (T[i][j].num)
        T[i][j].num = T[i][j].r - T[i][j].l + 1 - T[i][j].num;
    else
        T[i][j].num = T[i][j].r - T[i][j].l + 1;
}

void push(int i, int j)
{
    if (T[i][j].tag % 2)
    {
        T[i][j * 2].tag += T[i][j].tag;
        T[i][j * 2 + 1].tag += T[i][j].tag;
        T[i][j].tag = 0;
        cal(i, j * 2);
        cal(i, j * 2 + 1);
    }
    T[i][j].tag = 0;
}

void build(int l, int r, int i, int j)
{
    T[i][j].l = l, T[i][j].r = r;
    if (l == r)
    {
        T[i][j].num = (a[l] & (1ll << i) ? 1 : 0);
        return;
    }
    int mid = l + r >> 1;
    if (mid >= l)
        build(l, mid, i, j * 2);
    if (mid + 1 <= r)
        build(mid + 1, r, i, j * 2 + 1);
    T[i][j].num = T[i][j * 2].num + T[i][j * 2 + 1].num;
}

void change(int l, int r, int i, int j)
{
    if (T[i][j].l > r || T[i][j].r < l)
        return;
    push(i, j);
    if (T[i][j].l >= l && T[i][j].r <= r)
    {
        T[i][j].tag++;
        cal(i, j);
        return;
    }
    if (T[i][j].l <= r)
        change(l, r, i, j * 2);
    if (T[i][j].r >= l)
        change(l, r, i, j * 2 + 1);
    T[i][j].num = T[i][j * 2].num + T[i][j * 2 + 1].num;
}

int find(int l, int r, int i, int j)
{
    push(i, j);
    if (T[i][j].l > r || T[i][j].r < l)
        return 0;
    int cnt = 0;
    if (T[i][j].l >= l && T[i][j].r <= r)
        return T[i][j].num;
    if (T[i][j].l <= r)
        cnt += find(l, r, i, j * 2);
    if (T[i][j].r >= l)
        cnt += find(l, r, i, j * 2 + 1);
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 0; i < 21; i++)
        build(1, n, i, 1);

    int x, l, r;
    cin >> m;
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> l >> r;
            ll ans = 0;
            for (int i = 0; i < 21; i++)
                ans += (1ll << i) * find(l, r, i, 1);
            cout << ans << '\n';
        }
        else
        {
            cin >> l >> r >> x;
            int i = 0;
            while ((1ll << i) <= x)
            {
                if ((1ll << i) & x)
                {
                    change(l, r, i, 1);
                }
                ++i;
            }
        }
    }
}