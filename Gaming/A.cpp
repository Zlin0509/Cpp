#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
const int N = 110;
pair<int, int> a[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        cin >> a[i].second >> a[i].first;
    }
    sort(a + 1, a + n + 1);
    int k = 1;
    int sum = 0;
    if(a[1].first!=1)
    {
        cout << "MOREPROBLEMS" << endl;
    }
    else
    {
        sum += a[1].second;
    }
    for (int i = 2; i <= n;i++)
    {
        if(a[i+1].first==k)
        {
            if()
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
}