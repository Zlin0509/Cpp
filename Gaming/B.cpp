#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
int ans = 0;
struct Tree
{
    int l, r;
    int tag;
} t[400010]{};

void push_down(int i)
{
}

void change(int l, int r, int k, int i)
{
    if (t[i].l > r || t[i].r < l)
        return;
    push_down(i);
    if (t[i].l >= l && t[i].r <= r)
        t[i].tag += k;
    int mid = l + r >> 1;
    if (mid >= l)
        change(l, r, k, i * 2);
    if (mid + 1 <= r)
        change(l, r, k, i * 2 + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
}