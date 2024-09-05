#include "bits/stdc++.h"
using namespace std;
long long m, k, h;
inline bool check(long long x)
{
    long long cnt = 0, sum = x;
    if (x >= m)
        cnt = (x - m) / (m - k) + 1;
    sum += cnt * k;
    return sum >= h;
}
inline void Zlin()
{
    cin >> m >> k >> h;
    if (m == k || m >= h)
    {
        cout << min(m, h) << '\n';
        return;
    }
    long long l = m, r = h, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
}
int main()
{
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}