#include "bits/stdc++.h"
using namespace std;
string x;
int cnt1, cnt2;
inline void Zlin()
{
    cin >> x;
    for (int i = 0; i < 5; i++)
    {
        if (x[i] == 'Y')
            ++cnt1;
        if (x[i] == 'N')
            ++cnt2;
    }
    if (cnt1 < 4 && cnt2 < 2)
        cout << 0;
    if (cnt1 >= 4)
        cout << 1;
    if (cnt2 >= 2)
        cout << -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}