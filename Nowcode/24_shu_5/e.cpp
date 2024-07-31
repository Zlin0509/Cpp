#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 10;
int a[N], b[N];
inline void Zlin()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n;i++){
        cin >> b[i];
    }
    int s = 0,total=0;
    for (int i = 1; i <= n;i++){
        if(a[i]>b[i]){
            s++;
        }
        if(a[i]==b[i]){
            total++;
        }
    }
    s += (total + 1) / 2;
    cout << s;
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while(ttt--){
        Zlin();
    }
    return 0;
}