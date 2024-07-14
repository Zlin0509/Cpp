#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int a[7], b[7];

void solve()
{
    for (int i = 1; i <= 6; i++)
        cin >> a[i];
    for (int i = 1; i <= 6; i++)
        cin >> b[i];
    int sum = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (a[i] > b[j])
                sum++;
        }
    }
    //cout << sum << endl;
    int mod = gcd(36, sum);
    //cout << mod << endl;
    cout << sum / mod << "/" << 36 / mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    ttt = 1;
    while (ttt--)
        solve();
}