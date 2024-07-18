#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int n, m, k, x, y, l, r;
char c;
char ans[801][801]{};

void work()
{
    
}

void Zlin()
{
    cin >> n >> m >> k >> x >> y >> c;
    l = n + m;
    if (c == 'A')
    {
        if ((x & 1) == (y & 1))
            r = (n / 2) * (m / 2);
        else
            r = max(((n - 1) / 2) * (m / 2), ((m - 1) / 2) * (n / 2));
    }
    else
    {
        if ((x & 1) != (y & 1))
            r = (n / 2) * (m / 2);
        else
            r = max(((n - 1) / 2) * (m / 2), ((m - 1) / 2) * (n / 2));
    }
    if (k < l || k > r)
    {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    k -= n + m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans[i][j] = '.';
    ans[x][y] = c;
    work();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << (ans[i][j] == '.' ? c : ans[i][j]);
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}