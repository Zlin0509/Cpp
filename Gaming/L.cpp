#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int a[1000005] = {0};
void solve()
{
    ll n,max1;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    max1 = (n - 1) * (a[n] + a[1]);
    for (int i = 2; i <= n - 1;i++){
        ll sum1, sum2;
        sum1 = (i - 1) * (a[i] + a[1]);
        sum2 = (n - i) * (a[i] + a[n]);
        max1 = max(max1, sum1);
        max1 = max(max1, sum2);
    }
    cout << max1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}