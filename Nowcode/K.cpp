#include "bits/stdc++.h"
using namespace std;
int ans = INT_MAX, n, k;
priority_queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1, x; i <= n; i++)
    {
        cin >> x;
        q.push(x);
    }
    if (k == 1)
    {
        cout << q.top();
        return 0;
    }
    int cnt = 0, z;
    while (q.top() >= 1)
    {
        z = q.top();
        q.pop();
        z /= k;
        ++cnt;
        q.push(z);
        ans = min(ans, q.top() + cnt);
    }
    cout << ans;
}