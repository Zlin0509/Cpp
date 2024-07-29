#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
int a[1000005],b[1000005],p[1000005];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++){
        b[i] = 0;
        int c;
        cin >> c;
        a[c] = i;
        p[i] = c;
    }
    for (int i = 1; i <= n;i++){
        if(a[i]==i)
            b[i] = 1;
    }
    int s = 0, total = 0;
    for (int i = 1; i <= n;i++){
        if(b[i]==1){
            continue;
        }
        else{
            int q1 = a[i];
            if(a[q1]==i){
                s++;
                b[i] = 1;
                b[q1] = 1;
            }
            else{
                int q2 = a[q1];
                if(a[q2]==i){
                    total++;
                    b[i] = 1;
                    b[q1] = 1;
                    b[q2] = 1;
                }
                else{
                    int q3 = a[q2];
                    if(a[q3]==i){
                        total++;
                        b[i] = 1;
                        b[q1] = 1;
                        b[q2] = 1;
                        b[q3] = 1;
                    }
                    else{
                        total++;
                        b[i] = 1;
                        b[q1] = 1;
                        b[q2] = 1;
                        a[p[i]] = q3;
                        //cout << q3;
                    }
                }
            }
        }
    }
    if(s)
        total += (s+1) / 2 ;
    cout << total << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int ttt;
    cin >> ttt;
    while (ttt--)
        solve();
}