#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m1 = INT_MAX, ans = 0, m2, M = INT_MIN;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], m1 = min(m1, a[i]), M = max(M, a[i]);
    m2 = m1;
    ans = m1;
    while (m2 != M)
    {
        // cout << ans << '\n';
        bool check = true;
        for (int i = 1; i <= n; i++)
            if (a[i] == m2)
            {
                check = false;
                break;
            }
        if (check)
            ++ans;
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= m2 + 1)
                    ++ans;
            }
        }
        ++m2;
    }
    cout << ans << '\n';
    for (int i = 0; i < m1; i++)
        cout << "1 " << i << '\n';
    while (m1 != M)
    {
        bool check = true;
        for (int i = 1; i <= n; i++)
            if (a[i] == m1)
            {
                check = false;
                break;
            }
        if (check)
            cout << "1 " << m1 << '\n';
        else
        {
            for (int i = 1; i <= n; i++)
            {
                if (a[i] >= m1 + 1)
                    cout << "2 " << i << '\n';
            }
        }
        ++m1;
    }
}