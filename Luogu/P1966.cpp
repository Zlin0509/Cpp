#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

const ll Mod = 1e8 - 3;
int n;
int b[200010]{};
struct ss
{
    int a, id;
} a[200010]{};
vector<queue<int>> p(200010);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        p[b[i]].push(i);
    }
    sort(b[1], b[1 + n]);
}