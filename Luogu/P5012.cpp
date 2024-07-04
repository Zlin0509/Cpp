#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;

int a, b, x, y, last;
int n, T, num;
int f[1000010]{}, S[1000010]{};
int A[1000010]{}, B[1000010]{};
int Mx[1000010]{}, v[1000010]{};
vi c[1000010]{};

inline int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }
inline bool check(int x, int y) { return v[x] * y >= v[y] * x ? 1 : 0; }
inline void merge(int x, int y, int &tot, int &cnt)
{
    int fx = find(x), fy = find(y);
    if (fx == fy)
        return;
    --cnt;
    if (A[fx] == A[fy])
        tot -= S[fy] * S[fy];
    tot -= S[fx] * S[fx];
    S[fx] += S[fy];
    tot += S[fx] * S[fx];
    f[fy] = fx;
}

inline void prework()
{
    int tot, cnt;
    for (int i = 1; i <= num; i++)
    {
        tot = c[i].size(), cnt = c[i].size();
        for (auto it : c[i])
        {
            if (it != 1 && A[it - 1] <= B[i])
                merge(it, it - 1, tot, cnt);
            if (it != n && A[it + 1] <= B[i])
                merge(it, it + 1, tot, cnt);
        }
        v[i] = tot;
        if (check(i, Mx[cnt]))
            Mx[cnt] = i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> T;
    for (int i = 1; i <= n; i++)
        cin >> A[i], f[i] = i, S[i] = 1, B[i] = A[i];
    sort(B + 1, B + 1 + n);
    num = unique(B + 1, B + 1 + n) - B - 1;
    for (int i = 1; i <= n; i++)
        c[lower_bound(B + 1, B + 1 + num, A[i]) - B].push_back(i);

    prework();

    
}