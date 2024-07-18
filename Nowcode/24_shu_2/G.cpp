#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

ll ans = 0;
int m, x, y;
int dx[200010]{}, dy[200010]{};
char s[200010]{};
struct node
{
    int y, pos;
    friend bool operator<(node a, node b) { return a.y == b.y ? a.pos < b.pos : a.y < b.y; }
};
map<int, vector<node>> a;
map<int, int> usedx{}, usedy{};

int search(int xx, int yy)
{
    int l = 0, r = a[xx].size() - 1, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (a[xx][mid].y < yy)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> x >> y;
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    for (int i = 1; i <= m; i++)
    {
        if (s[i] == 'W')
            dx[i] = dx[i - 1], dy[i] = dy[i - 1] + 1;
        else if (s[i] == 'S')
            dx[i] = dx[i - 1], dy[i] = dy[i - 1] - 1;
        else if (s[i] == 'A')
            dx[i] = dx[i - 1] - 1, dy[i] = dy[i - 1];
        else if (s[i] == 'D')
            dx[i] = dx[i - 1] + 1, dy[i] = dy[i - 1];
        a[dx[i]].push_back({dy[i], i});
        ++usedy[dy[i]];
    }
    for (int i = 1; i <= m; i++)
    {
        if (!usedx[dx[i]])
        {
            ++usedx[dx[i]];
            sort(a[dx[i]].begin(), a[dx[i]].end());
        }
    }
    for (int i = 1, xx, yy; i <= m; i++)
    {
        xx = dx[i] + x, yy = dy[i] + y;
        if (usedx[xx] && usedy[yy])
        {
            int pos = search(xx, yy);
            while (pos < a[xx].size() && a[xx][pos].y == yy && a[xx][pos].pos < i)
                ++pos;
            if (pos < a[xx].size() && a[xx][pos].y == yy)
            {
                // cout << a[xx][pos].pos << ' ' << a[xx].size() << '\n';
                ans += m - a[xx][pos].pos + 1;
            }
        }
    }
    cout << ans;
}