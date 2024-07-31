#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int a[N];
long long mo = 998244353;
inline void Zlin()
{
    int n,s=0;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
        s += a[i];
    }
    int j = n;
    for (int i = 1; i <= n-1;i++){
        if(s/j>=a[i]){
            int p = a[i];
            a[i] = s / j;
            a[i + 1] = a[i + 1] - (a[i] - p);
            s = s - a[i];
            j--;
        }
        else{
            s = s - a[i];
            j--;
        }
    }
    a[n] = s;
    long long sum = 1;
    for (int i = 1; i <= n;i++){
        cout << a[i] << " ";
        sum = sum * a[i];
        sum = sum % mo;
    }
    cout << sum << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        Zlin();
    }
    return 0;
}