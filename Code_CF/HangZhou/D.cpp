#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<long long>;
using vi = vector<int>;

void solve()
{
    int n;
    cin >> n;
    if (n == 3)
    {
        cout << "1 -10 6 6 -10 1 " << '\n';
        return;
    }
    int x = 1;
    int y = 3 - n;
    cout << x << " ";
    for (int i = 1; i <= n - 1; i++)
        cout << 2 << ' ' << -1 << ' ';
    cout << y << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--)
        solve();
}