#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, cnt = 0, s = 0, l = 0;
int a[200010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], l = max(l, a[i]);
    s = a[1];
    for (int i = 2; i <= n; i++)
        s = gcd(s, a[i]);
    cnt = n - l / s;
    cout << (cnt & 1 ? "Alice" : "Bob");
}