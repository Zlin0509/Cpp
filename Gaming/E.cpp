#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, z;
int a[200010]{};

bool check(int k)
{
    for (int i = 1; i <= k; i++)
    {
        if (a[n - k + i] - a[i] < z)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> z;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = n / 2, mid;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid;
    }
    cout << l;
}