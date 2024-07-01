#include "bits/stdc++.h"
using namespace std;

using ll = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

ll n;
ll a[100010]{}, b[100010]{};
ll l, r, c, mid, z;

ll check(ll t)
{
    ll sum = 0;
    for (int i = 1; i <= n; i++)
        if (t >= b[i])
            sum += 1 + (t - b[i]) / a[i];
    // cout << sum << '\n';
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    cin >> l >> r >> c;
    z = check(l - 1);
    while (l < r)
    {
        mid = (l + r) / 2ll;
        if (check(mid) - z < c)
            l = mid + 1;
        else
            r = mid;
        // cout << mid << ' ';
        // cout << check(l) << '\n';
    }
    // cout << l << '\n';

    if (check(l) - z < c)
        cout << "-1";
    else
        cout << l;
}