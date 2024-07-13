#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int f[100], d[100], e[100];
void inf()
{
    ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c, n;
    cin >> a >> b >> c;
    for (int i = 60; i >= 0; i--)
    {
        int k = 1ll << i;
        if (k & n)
            f[i] = 1;
    }
}
