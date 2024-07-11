#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int x, y;
int ans;
set<int> aa;

void cal(int a, int b)
{
    if (a < b)
        swap(a, b);
    for (int i = 1, j; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            if (b % i == 0)
                aa.insert(i);
            j = a / i;
            if (b % j == 0)
                aa.insert(j);
        }
    }
}

void solve()
{
    cin >> x >> y;
    ans = 0;
    aa.clear();
    if (x % 2 + y % 2 == 1)
        aa.insert(2);
    cal(x - 1, y - 1);
    cal(x, y - 2);
    cal(x - 2, y);
    cout << aa.size() << ' ';
    for (auto it : aa)
        cout << it << ' ';
    cout << '\n';
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