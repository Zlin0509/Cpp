#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m;
int a[200010]{};
int t[33][200010]{};

void add(int i, int j, int z)
{
    for (; j <= n; j += lowbit(j))
        t[i][j] += z;
}

int find(int i, int l, int r)
{
    int ans = 0;
    for (; r; r -= lowbit(r))
        ans += t[i][r];
    --l;
    for (; l; l -= lowbit(l))
        ans -= t[i][l];
    return ans;
}

void change(int i, int l, int r)
{
    for (; r; r -= lowbit(r))
    {
        if (t[i][r])
        {
            t[i][r] = lowbit(r) - t[i][r];
        }
        else
        {
            t[i][r] = lowbit(r);
        }
    }
    --l;
    for (; l; l -= lowbit(l))
    {
        if (t[i][l] == lowbit(l))
        {
            t[i][l] = 0;
        }
        else
        {
            t[i][l] = lowbit(l) - t[i][l];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= n; j++)
    {
        int i = 0;
        while ((1ll << i) <= a[j])
        {
            if ((1ll << i) & a[j])
                add(i, j, 1);
            ++i;
        }
    }
    cin >> m;
    int x, l, r;
    while (m--)
    {
        cin >> x;
        if (x == 1)
        {
            cin >> l >> r;
            int ans = 0;
            for (int i = 0; i < 33; i++)
                ans += (1ll << i) * find(i, l, r);
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
                    change(i, l, r);
                }
                ++i;
            }
        }
    }
}