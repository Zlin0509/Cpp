#include "bits/stdc++.h"
using namespace std;

using ll = unsigned long long;
using vi = vector<int>;
using vll = vector<long long>;

void solve()
{
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, sum = 0;
    ll n, k1, k2;
    cin >> a >> b >> c >> n;
    if (a == b)
    {
        sum++;
    }
    if (a == c)
    {
        sum++;
    }
    if (b == c)
    {
        sum++;
    }
    k1 = n;
    k2 = n * n - 3 * n + 2;
    int t1 = 1, t2 = 1;
    ll q1 = k1, q2 = k2;
    if(sum==1){
        q2 = q2 / 2;
    }
    while (q1)
    {
        t1 = t1++;
        q1 = q1 >> 1;
    }
    while (q2)
    {
        t2 = t2++;
        q2 = q2 >> 1;
    }
    if(n==2){
        cout << 0;
    }
    else{
        if(sum==3){
            if(n==3)
                cout << 1;
            else{
                cout << n;
            }
        }
        else{
            if (t1 + t2 >= 64)
            {
                ll su1 = 1ll << t1;
                ll su2 = 1ll << (64 - t1);
                ll total = 0;
                total = k1 % su1 * su2 + k2 % su2 * su1;
            }
            else
            {
                cout << k1 * k2 << "\n";
            }
        }
    }
}