#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
using ull = unsigned long long;
ull x, a, b;
void solve()
{
    cin >> x;
    a = 0;
    b = 0;
    a = sqrt(4 * x + 1);
    if (a * a != 4 * x + 1)
    {
        b++;
    }
    b += a + 1;
    cout << b << "\n";
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