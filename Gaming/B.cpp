#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;

void solve()
{
    cin >> n;
    if (n % 3 == 0)
        cout << n / 3 << ' ' << n / 3 << '\n';
    else if (n % 3 == 1)
        cout << n / 3 + 1 << ' ' << n / 3  << '\n';
    else
        cout << n / 3 << ' ' << n / 3 + 1 << '\n';
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