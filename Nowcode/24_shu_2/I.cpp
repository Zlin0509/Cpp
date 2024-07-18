#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
int a[6005], b[6005] = {0};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> a[i];
    }
    ll sum = 0, q1 = 0, q2 = 0, k = 2 * n;
    for (int i = n; i >= 1; i--)
    {
        q1 = 0, q2 = 0;
        for (int j = 1; j <= k; j++)
        {
            //cout << a[j] << " ";
            if (a[j] == i)
            {
                if(q1==0){
                    q1 = j;
                }
                else{
                    q2 = j;
                }
            }
        }
        //cout << q1 << " " << q2 << "\n";
        if (q1 != 0 && q2 != 0){
            sum += i * (q2 - q1 + 1);
            k = k - (q2 - q1 + 1);
        }
        for (int j = q1; j <= k; j++)
        {
            a[j] = a[j + (q2 - q1 + 1)];
        }
    }
    cout << sum;
}