#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
void solve()
{
    long long x;
    cin >> x;
    int x2 = x;
    for (int i = 0; i <= 32; i++)
    {
        ll a = 1ll << i;
        if (a >= x)
            break;
        if (a & x)
        {
            x2 -= a;

            if (gcd(x2, x) == (x2 ^ x))
            {

                cout << x2 << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}