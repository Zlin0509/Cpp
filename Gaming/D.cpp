#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n, ans = 0;
int a[1010]{};
set<int> used;
int m[1000010]{}, M[1000010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    char c;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        used.insert(a[i]);
    }
    int cnt = 0, MM = 0;
    for (int i = 1; i <= n; i++)
    {
        ++cnt;
        if (a[i] != a[i + 1])
        {
            MM = max(MM, cnt);
            m[a[i]] = max(m[a[i]], cnt);
            cnt = 0;
        }
    }
    for (auto z : used)
    {
        vi b;
        cnt = 0;
        memset(M, 0, sizeof(M));
        for (int i = 1; i <= n; i++)
            if (a[i] != z)
                b.push_back(a[i]);
        b.push_back(0);
        for (int i = 0; i < b.size() - 1; i++)
        {
            ++cnt;
            if (b[i] != b[i + 1])
            {
                M[b[i]] = max(M[b[i]], cnt);
                cnt = 0;
            }
        }
        for (auto it : used)
            ans = max(ans, M[it] - MM);
    }
    cout << ans;
}