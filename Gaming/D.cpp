#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

const ll mo = 998244353;

string s, t;
int len1, len2;
int f1[110][26], f2[110][26];
ll qpw(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % mo;
        x = x * x % mo;
        y >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    cin >> t;
    len1 = s.length(), len2 = t.length();
    s = ' ' + s;
    t = ' ' + t;

    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
            f1[i][t[j] - 'a'] = f1[i - 1][t[j] - 'a'] * 2 % mo;

        for (int j = 2; j <= len2; j++)
            f2[i][t[j] - 'a'] = f1[i - 1][t[j - 1] - 'a'];
    }
    cout << f1[len2][t[len2] - 'a'];
}