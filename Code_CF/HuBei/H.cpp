#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m, k;
int M[1010][1010]{};

void solve()
{
    cin >> n >> m >> k;
    for (int i = 1, x, y; i <= k; i++)
    {
        cin >> x >> y;
        cin >> M[x][y];
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}