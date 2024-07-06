#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;

void solve()
{
    cin >> n;
    if (n % 2 == 0)
    {
        cout << n / 2 << ' ' << n / 2 << '\n';
        return;
    }
    int x1 = n / 2, x2 = n / 2 + 1, cnt = 0;
    while (x1 % 10 == 9)
    {
        x1 /= 10;
        ++cnt;
    }
    x1 = n / 2;
    // cout << cnt;
    for (int i = 0; i < cnt; i++)
    {
        // cout << pow(10, i) << '\n';
        if (i % 2 == 0)
        {
            x1 -= 4 * pow(10, i);
            x2 += 4 * pow(10, i);
        }
        else
        {
            x1 -= 5 * pow(10, i);
            x2 += 5 * pow(10, i);
        }
        // cout << x1 << ' ' << x2 << '\n';
    }
    cout << x1 << ' ' << x2 << '\n';
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