#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, x, y;
        cin >> n >> m >> x >> y;
        cout << (n - m) * x + m * y;
        cout << "\n";
    }
}