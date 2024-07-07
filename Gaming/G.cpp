#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int n;
string s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    if (n == 1)
    {
        if (s[0] == '0')
        {
            cout << "No";
            return 0;
        }
        cout << "Yes";
        return 0;
    }
    if (s[0] == s[1] || s[n - 1] == s[n - 2])
    {
        cout << "No";
        return 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (s[i] == '1' && (s[i - 1] == '1' || s[i + 1] == '1'))
        {
            cout << "No";
            return 0;
        }
        if (s[i] == '0' && s[i - 1] == '0' && s[i + 1] == '0')
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}