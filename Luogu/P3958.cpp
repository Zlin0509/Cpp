#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, h, r;

struct ss
{
    double x, y, z;
} T[1010]{};

double cal(double xa, double ya, double za, double xb, double yb, double zb)
{
    return sqrt(pow(xa - xb, 2) + pow(ya - yb, 2) + pow(za - zb, 2));
}

void solve()
{
    cin >> n >> h >> r;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int TTT;
    cin >> TTT;
    while (TTT--)
        solve();
}