#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t-->0){
        int n, m;
        cin >> n >> m;
        int max1 = 0, max2 = 0;
        for (int i = 0; i < m;i++){
            int a, b;
            cin >> a >> b;
            max1 = max(max1, a);
            max2 = max(max2, b);
        }
        //cout << max1 << max2;
        if(max1+max2>n)
            cout << "IMPOSSIBLE" << "\n";
        else{
            for (int i = 1; i <= max1;i++)
            {
                cout << "R";
            }
            for (int i = 1; i <= n - max1;i++){
                cout << "W";
            }
            cout << "\n";
        }
    }
}