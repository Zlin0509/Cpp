#include "bits/stdc++.h"
using namespace std;
int n, m;
inline void Zlin()
{
    cin >> n >> m;
    if (m > n - 3)
    {
        cout << "-1\n";
        return;
    }
    vector<int> ans;
    for (int i = n - m; i <= n; i++)
        ans.push_back(i);
    int cnt = n - m - 1;
    if (cnt & 1)
    {
        for (int i = cnt; i >= 1; i -= 2)
            ans.push_back(i);
        for (int i = 2; i <= cnt; i++)
            ans.push_back(i);
    }
    else
    {
        for (int i = cnt; i >= 1; i -= 2)
            ans.push_back(i);
        for (int i = 1; i <= cnt; i++)
            ans.push_back(i);
    }
    for (auto it : ans)
        cout << it << ' ';
    cout << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}