#include "bits/stdc++.h"
using namespace std;
vector<int> a;
int main()
{
    int ttt;
    cin >> ttt;
    for (int i = 1, x; i <= ttt; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for (auto it : a)
        cout << it << ' ';
}