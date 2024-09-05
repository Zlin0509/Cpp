#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;

inline void Zlin()
{
    long long n, k;
    cin >> n >> k;
    k = min(k, n - k);
    if(n==k*2){
        cout << n;
    }
    else{
        cout << n * k + 1;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
        Zlin();
}