#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, q, l1, r1, l2, r2;
char a[100010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    while (q--)
    {
        int cnt = 0;
        int used[30]{};
        cin >> l1 >> r1 >> l2 >> r2;
        for (int i = l1; i <= r1; i++)
        {
            if (a[i] != a[i + l2 - l1])
            {
                if (!used[a[i] - 'a'])
                    ++cnt;
                if (!used[a[i + l2 - l1] - 'a'])
                    ++cnt;
                ++used[a[i] - 'a'];
                ++used[a[i + l2 - l1] - 'a'];
            }
        }
        cout << cnt << '\n';
        for (int i = 0; i < 26; i++)
            if (used[i])
                cout << char('a' + i);
        cout << '\n';
    }
}