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
    ll x = 25 * 5 * 26 + 100 * 26 + 11, y = 26 * 26;
    cout << x * qpw(y, mo - 2);
}