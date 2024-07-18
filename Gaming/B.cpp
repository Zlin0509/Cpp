#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const ll N = 1000000007;
ll ans = 0;
ll n, cnt = 0;
stack<ll> a;

void Zlin()
{
    cin >> n;
    for (int i = 1, x, y; i <= n; i++)
    {
        cin >> x >> y;
        while (cnt && x--)
        {
            ans -= cnt * a.top();
            ans = (ans + (abs(ans) / N + 10) * N) % N;
            --cnt;
            a.pop();
        }
        ++cnt;
        ans = (ans + cnt * y) % N;
        a.push(y);
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