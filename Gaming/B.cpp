#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n;
int a[1010]{};
int f1[1010][22], f2[1010][22];
ll ans = 0;

const ll mod = 998244353;
ll d[1010];
void quick_pow()
{
    d[1] = 1;
    for (int i = 2; i <= n; i++)
        d[i] = d[i - 1] * i % mod;
}
inline void prework()
{
    for (int i = 1; i <= n; i++)
        f1[i][0] = f2[i][0] = a[i];
    int t = log(n) / log(2) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
        {
            f1[i][j] = max(f1[i][j - 1], f1[i + (1 << (j - 1))][j - 1]);
            f2[i][j] = min(f2[i][j - 1], f2[i + (1 << (j - 1))][j - 1]);
        }
}

inline int query(int l, int r)
{
    int k = log(r - l + 1) / log(2);
    return max(f1[l][k], f1[r - (1 << k) + 1][k]) - min(f2[l][k], f2[r - (1 << k) + 1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    prework();
    quick_pow();
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            ans += query(i, j);
    ll ans2 = 1;
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
            sum++;
        else
        {
            ans2 = ans2 * d[sum] % mod;
            sum = 1;
        }
    }
    ans2 = ans2 * d[sum] % mod;
    if (a[1] != a[n])
        ans2 = ans2 * 2 % mod;
    cout << ans << ' ' << ans2 << '\n';
}