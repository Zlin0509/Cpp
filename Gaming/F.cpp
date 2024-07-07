#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

ll u, v, x1 = 0, x2 = 0, x3 = 0;
int k = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> u >> v;

    if (u == 0 && v == 0)
    {
        cout << 0;
        return 0;
    }
    if (u == v)
    {
        cout << 1 << '\n';
        cout << u;
        return 0;
    }
    if (u > v)
    {
        cout << -1;
        return 0;
    }

    v -= u;
    x1 = u;
    while ((1ll << k) <= v)
        ++k;
    while (k >= 0)
    {
        if ((1ll << (k + 1)) <= v)
        {
            if ((1ll << k) & u)
            {
                x2 += (1ll << k);
                x3 += (1ll << k);
            }
            else
            {
                x1 += (1ll << k);
                x2 += (1ll << k);
            }
            v -= (1ll << (k + 1));
        }
        --k;
    }
    if (v)
    {
        cout << -1;
        return 0;
    }
    if (x3)
    {
        cout << 3 << '\n';
        cout << x1 << ' ' << x2 << ' ' << x3;
        return 0;
    }
    cout << 2 << '\n';
    cout << x1 << ' ' << x2;
}