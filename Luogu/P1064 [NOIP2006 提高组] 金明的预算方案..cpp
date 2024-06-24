#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[40010]{}, v[65]{}, p[65]{}, q[65]{};
vector<vector<int>> qq(65);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> p[i] >> q[i];
        if (q[i])
            qq[i].push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (!q[i])
        {
            if (qq[i].size() == 0)
            {
            }
            if (qq[i].size() == 1)
            {
            }
            if (qq[i].size() == 2)
            {
            }
        }
    }
}