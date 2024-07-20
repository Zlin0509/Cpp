#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
int a[2010]{}, used[2010]{};
map<pair<int, int>, vi> to;
stack<pair<int, int>> ans;

void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
}