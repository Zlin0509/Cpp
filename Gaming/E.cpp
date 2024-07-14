#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int a[1000005], b[1000005], c[1000005], d[1000005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    for (int i = 3; i <= n;i++){
        b[i] = i - 2;
        c[i] = i - 2;
    }
    d[1] = 1;
    d[n] = 1;
    for (int i = 2; i <= n - 1;i++){
        d[i] == 2;
    }
    if (a[1] == 2 || a[n] == 2)
    {
            cout << "NO" << "\n";
            return;
    }
    for (int i = 1; i <= n-1;i++){
        if(a[i]==0){
            if(b[i]-c[i]==0){
                continue;
            }
            else{
                if(b[i]>c[i]){
                    b[i + 1]++;
                }
                else{
                    c[i + 1]++;
                }
            }
        }
        else if(a[i]==1){
            if(b[i]-c[i]==1||c[i]-b[i]==1){
                continue;
            }
            else{
                b[i + 1]++;
            }
        }
        else if(a[i]==2){
            if(b[i]-c[i]==1||c[i]-b[i]==1){
                if(b[i]>c[i]){
                    c[i+1]++;
                }
                else{
                    b[i + 1]++;
                }
            }
            else{
                cout << "NO" << "\n";
                return;
            }
        }
    }
    if(b[n]-c[n]==a[n]||c[n]-b[n]==a[n]){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    solve();
}