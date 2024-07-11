#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve()
{
    string a, b;
    cin >> a >> b;
    int l1, l2, i1 = 0, i2 = 0, sum1 = 0, sum2 = 0;
    l1 = a.size();
    while (i1 < l1)
    {
        if (a[i1] == 'B')
            sum1++;
        i1++;
    }
    l2 = b.size();
    while (i2 < l2)
    {
        if (b[i2] == 'B')
        {
            sum2++;
        }
        i2++;
    }
    i1 = 0;
    i2 = 0;
    for (int i = 0; i < l1; i++)
    {
        if (a[i] != 'B')
        {
            a[i1] = a[i];
            i1++;
        }
    }
    for (int i = 0; i < l2; i++)
    {
        if (b[i] != 'B')
        {
            b[i2] = b[i];
            i2++;
        }
    }
    int k1 = 0, k2 = 0;
    while (k1 < i1)
    {
        if (a[k1] == a[k1 + 1] && k1 + 1 < i1)
        {
            for (int i = k1; i < i1 - 2; i++)
            {
                a[i] = a[i + 2];
            }
            i1 = i1 - 2;
            k1 = 0;
        }
        else
        {
            k1++;
        }
    }
    while (k2 < i2)
    {
        if (b[k2] == b[k2 + 1] && k2 + 1 < i2)
        {
            for (int i = k2; i < i2 - 2; i++)
            {
                b[i] = b[i + 2];
            }
            i2 = i2 - 2;
            k2 = 0;
        }
        else
        {
            k2++;
        }
    }
    //cout << sum1 << " " << sum2 << "\n";
    int o1, o2;
    o1 = sum1 % 2;
    o2 = sum2 % 2;
    // cout << k2;
    if ((k1 != k2) || (o1 != o2))
    {
        cout << "NO" << "\n";
    }
    else
    {
        if (k1 == 0)
        {
            cout << "YES" << "\n";
        }
        else
        {
            int p = 0;
            for (int i = 0; i < k1; i++)
            {
                if (a[i] != b[i])
                {
                    p = 1;
                    break;
                }
            }
            if (p == 0)
            {
                cout << "YES" << "\n";
            }
            else
            {
                cout << "NO" << "\n";
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}