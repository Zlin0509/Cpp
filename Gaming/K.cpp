#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t, n, k;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        if (k >= n)
            cout << "Alice";
        else if (k == 1)
            cout << (n & 1 ? "Alice" : "Bob");
        else if (n & 1)
            cout << "Alice";
        else if ((n / 2) & 1)
            cout << "Alice";
        else
        {
            int x = 1;
            while (x * 2 <= k && n % 2 == 0)
            {
                n /= 2;
                x *= 2;
            }
            cout << (n & 1 ? "Alice" : "Bob");
        }
        if (i != t)
            cout << '\n';
    }
}