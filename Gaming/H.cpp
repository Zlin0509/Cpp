#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

const int n = 500000;

int z[5000010]{};
map<pair<int, int>, int> num{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q, a, x, y, l = n, r = 1;
    cin >> q;
    while (q--)
    {
        cin >> a >> x >> y;
        if (a == 1)
        {
            z[x] += y;
            for (int i = 1; i <= x; i++)
                num[{i, x % i}] += y;
        }
        else
        {
            cout << num[{x, y}] + z[y] << '\n';
        }
    }
}