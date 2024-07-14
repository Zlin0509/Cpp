#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int a[550][550] = {0}, b[550][550] = {0};
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            b[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        b[i][i] = 1;
    }
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][i] == 0)
        {
            p = 0;
            for (int j = i + 1; j <= n; j++)
            {
                if (a[j][i] == 0)
                {
                    continue;
                }
                else
                {
                    // cout << j;
                    p = 1;
                    for (int k = i; k <= n; k++)
                    {
                        a[i][k] = (a[i][k] ^ a[j][k]);
                    }
                    for (int k = 1; k <= n; k++)
                    {
                        b[i][k] += b[j][k];
                    }
                    break;
                }
            }
            if (p == 0)
            {
                break;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (j == i || a[j][i] == 0)
            {
                continue;
            }
            for (int k = i; k <= n; k++)
            {
                a[j][k] = (a[i][k] ^ a[j][k]);
            }
            for (int k = 1; k <= n; k++)
            {
                b[j][k] += b[i][k];
            }
        }
    }
    if (p == 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (b[i][j] % 2 == 1)
                {
                    cout << j << " ";
                }
            }
            cout << "\n";
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}