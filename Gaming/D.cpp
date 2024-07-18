#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

const ll N = 2097152;
stack<ll> a;
ll n, cnt = 0, ans = 0;
int t[66]{};

void Zlin()
{
    cin >> n;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        while (x--)
        {
            for (int i = 32; i >= 0; i--)
            {
                if ((1ll << i) & a.top())
                {
                    t[i] = cnt - t[i];
                    t[i + 1] -= t[i];
                }
            }
            --cnt;
            a.pop();
        }
        a.push(y);
        ++cnt;
        ans = 0;
        for (int i = 0; i <= 10; i++)
            cout << t[i] << ' ';
        cout << '\n';
        for (int i = 0; i <= 32; i++)
        {
            if ((1ll << i) & y)
            {
                t[i + 1] += t[i];
                t[i] = cnt - t[i];
            }
            ans = (ans + (t[i] & 1) * (1ll << i)) % N;
        }
        for (int i = 0; i <= 10; i++)
            cout << t[i] << ' ';
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}