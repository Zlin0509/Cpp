#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, m;
int a[2001]{}, b[2001]{};
int used[1000010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ++used[a[i]];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        ++used[b[i]];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!used[a[i] + b[j]])
            {
                cout << a[i] << ' ' << b[j];
                return 0;
            }
        }
    }
}