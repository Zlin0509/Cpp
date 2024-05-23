#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    char *x;
    cin >> x;
    char *check = "ABC";
    for (int i = 0; i < n - 3; i++)
    {
        if (!strncmp(x + i, check, 3))
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    cout << "-1" << '\n';
}