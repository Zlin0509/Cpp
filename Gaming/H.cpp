#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
int sum[200010]{};
priority_queue<int, vi, greater<int>> p;
priority_queue<int, vi, less<int>> q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1, x, c; i <= n; i++)
    {
        cin >> x >> c;

        if (c == 1)
            p.push(sum[i - 1]);
        else
            q.push(sum[i - 1]);
        sum[i] = sum[i - 1] + x;
    }
    if (q.empty())
    {
        cout << "Infinity";
        return 0;
    }
    if (!p.empty() && q.top() >= p.top())
    {
        cout << "Impossible";
        return 0;
    }
    cout << 1899 - q.top() + sum[n];
}