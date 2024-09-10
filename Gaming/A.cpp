#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int n, m;
char a[3010][3010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == 'c' && a[i][j + 1] == 'c' && a[i + 1][j] == 'p' && a[i + 1][j + 1] == 'c')
                ++ans;
        }
    cout << ans;
}