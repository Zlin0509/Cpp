#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
inline int cal(ll z)
{
    int sum = 0;
    while (z)
    {
        sum += z % 10;
        z /= 10;
    }
    return sum;
}
inline void Zlin()
{
    ll ans = 0, n;
    unordered_map<int, int> used;
    cin >> n;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == cal(i))
        {
            used[i] = 1;
            ++ans;
        }
    }
    for (ll i = 1; i * i < n; i++)
    {
        ll m = n / i;
        if (!used[m] && n % m == cal(m))
        {
            used[m] = 1;
            ++ans;
        }
    }
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
        Zlin();
}