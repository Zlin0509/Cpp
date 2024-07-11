#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
int used[1100][66]{};
char c;
int r, r1, r2, o, o1, o2;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void dfs(int o, int r)
{
    if (r > 63)
        return;
    used[o][r] = 1;
    for (int i = 0, oo, rr; i < 4; i++)
    {
        oo = (o + dx[i] + 1080) % 1080;
        rr = r + dy[i];
        if (rr >= 0 && !used[oo][rr])
            dfs(oo, rr);
    }
}

void solve()
{
    for (int i = 0; i < 1080; i++)
        memset(used[i], 0, sizeof(used[i]));
    cin >> n;
    while (n--)
    {
        cin >> c;
        if (c == 'C')
        {
            cin >> r >> o1 >> o2;
            if (o1 < o2)
            {
                for (int i = o1 * 3 + 1; i <= o2 * 3 + 1; i++)
                    used[i][r * 3 + 1] = -1;
            }
            else
            {
                for (int i = 0; i <= o2 * 3 + 1; i++)
                    used[i][r * 3 + 1] = -1;
                for (int i = o1 * 3; i < 1080; i++)
                    used[i][r * 3 + 1] = -1;
            }
        }
        else
        {
            cin >> r1 >> r2 >> o;
            for (int i = r1 * 3 + 1; i <= r2 * 3 + 1; i++)
                used[o * 3 + 1][i] = -1;
        }
    }
    for (int i = 0; i < 1080; i++)
        used[i][0] = 1;
    for (int i = 0; i < 1080; i++)
        dfs(i, 0);
    for (int i = 0; i < 1080; i++)
        if (used[i][63] == 1)
        {
            cout << "YES" << '\n';
            return;
        }
    cout << "NO" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}