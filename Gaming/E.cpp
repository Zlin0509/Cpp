#include "bits/stdc++.h"
using namespace std;
int n, z;
int a[200010]{};
bool check(int k)
{
    for (int i = 1; i <= k; i++)
        if (a[n - k + i] - a[i] < z)
            return true;
    return false;
}
int main()
{
    cin >> n >> z;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    int l = 0, r = n / 2, mid;
    while (l < r)
    {
        mid = l + r + 1 >> 1;
        check(mid) ? r = mid - 1 : l = mid;
    }
    cout << l;
}