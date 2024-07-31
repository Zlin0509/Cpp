#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll sum[N];
int ans[N];
inline void Zlin()
{
    int n, k;
    cin >> n >> k;
    sum[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (i + 1) / 2;
        // cout << sum[i] << " ";
    }
    // cout << endl;
    if (sum[n] < k)
    {
        cout << "No";
        return;
    }
    int flag = 0;
    int now = 0;
    int sumx = 1;
    if(n==0&&k==0)
    {
        cout << "Yes" << "\n";
        return;
    }
    else if(n==0)
    {
        cout << "No" << "\n";
        return;
    }
    if(k==0&&n!=1)
    {
        cout << "Yes" << "\n";
        for (int i = 1; i <= n;i++)
        {
            
        }
    }
    for (int i = n; i >= 1; i--)
    {
        while (k >= sum[i] && sumx <= n)
        {
            k -= sum[i];
            for (int j = 1; j <= i + 1; j++)
            {
                ans[sumx] = now;
                sumx++;
            }
            now = (now + 1) % 3;
        }
    }
     cout << sumx << endl;
    if (sumx <= n + 1)
    {
        cout << "Yes" << '\n';
        for (int i = 1; i <= sumx - 1; i++)
            cout << ans[i] << " ";
        for (int i = sumx; i <= n; i++)
        {
            if ((i - sumx) % 4 == 1 || (i - sumx) % 4 == 3)
                cout << ans[sumx - 1] << " ";
            else if ((i - sumx) % 4 == 0)
                cout << now << " ";
            else
                cout << (now + 1) % 3 << " ";
        }
    }
    else
        cout << "No" << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
    return 0;
}