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

    int n;
    cin >> n;
    if (n % 3 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n / 3; j++)
            {
                if (i % 3 == 1)
                {
                    cout << "aab";
                }
                else if (i % 3 == 2)
                {
                    cout << "d.b";
                }
                else
                {
                    cout << "dcc";
                }
            }
            cout << '\n';
        }
        return 0;
    }
    if (n % 7 == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n / 7; j++)
            {
                if (i % 7 == 1)
                {
                    cout << "aabb..z";
                }
                else if (i % 7 == 2)
                {
                    cout << "b..zz.z";
                }
                else if (i % 7 == 3)
                {
                    cout << "ba....q";
                }
                else if (i % 7 == 4)
                {
                    cout << ".a..aaq";
                }
                else if (i % 7 == 5)
                {
                    cout << "..a..bp";
                }
                else if (i % 7 == 6)
                {
                    cout << "..a..bp";
                }
                else
                {
                    cout << "zzqqpp.";
                }
            }
            cout << '\n';
        }
        return 0;
    }
    cout << "-1";
}