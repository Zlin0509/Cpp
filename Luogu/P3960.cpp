#include "bits/stdc++.h"
using namespace std;
#define lowbit(x) (x & (-x))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
const int N = 3e5 + 10;

int n, m, q;
struct ss
{
    int x, y, id;
    friend bool operator<(const ss &a, const ss &b) { return a.x == b.x ? a.id < b.id : a.x < b.x; }
} c[N];
int t[N], change[N], ans[N], len[N], len2[N], h[N], arr[N * 3];
bool cmp(const ss &a, const ss &b) { return a.id < b.id; }
void add(int *tree, int size, int i, int k)
{
    for (; i <= size; i += lowbit(i))
        tree[i] += k;
}

int query(int *tree, int l, int r)
{
    int sum = 0;
    for (; r; r -= lowbit(r))
        sum += tree[r];
    --l;
    for (; l; l -= lowbit(l))
        sum -= lowbit(l);
    return sum;
}

int search(int *arr, int size, int num)
{
    int l = 1, r = size, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if (query(arr, 1, mid) < num)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

void Zlin()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= q; i++)
        cin >> c[i].x >> c[i].y, c[i].id = i;
    sort(c + 1, c + 1 + q);
    for (int i = 1; i <= n; i++)
        len[i] = m - 1;
    for (int i = 1, top = 0, pos; i <= q; i++)
    {
        if (c[i - 1].x != c[i].x)
            while (top)
                add(t, m - 1, change[top--], 1);
        if (c[i].y > len[c[i].x])
            continue;
        pos = search(t, m - 1, c[i].y);
        add(t, m - 1, pos, -1);
        change[++top] = pos;
        --len[c[i].x];
        ans[i] = (c[i].x - 1) * m + pos;
    }
    sort(c + 1, c + 1 + 1, cmp);
    memset(t, 0, sizeof(t));
    for (int i = 1; i <= n; i++)
        arr[q + i] = i * m, len2[i] = m - 1, len[i] = 0;
    len[n + 1] = n, h[n + 1] = q;
    for (int i = 1, pos; i <= q; i++)
    {

        if (ans[i])
        {
        }
        else
        {
        }
    }

    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}