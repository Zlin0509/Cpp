#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const int N = 1e6 + 5;
int n;
ll a[N], ans, cnt;
void solve()
{
    ans = 0, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1, k; i <= n; i++)
    {
        k = 1;
        while (a[i] != i)
        {
            swap(a[i], a[a[i]]);
            ++k;
            if (k == 4)
            {
                k = 1;
                ++ans;
            }
        }
        if (k == 2)
            cnt += 2;
        if (k == 3)
            ++ans;
    }
    ans += cnt / 4;
    if (cnt % 4)
        ++ans;
    cout << ans << '\n';
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