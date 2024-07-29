#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;
double ans1, ans2;
void solve()
{
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double x = abs(x1 - x2);
    double y = abs(y1 + y2);
    ans1 = sqrt(x * x + y * y);
    x = abs(x1 + x2);
    y = abs(y1 - y2);
    ans2 = sqrt(x * x + y * y);
    printf("%.10lf\n", min(ans1, ans2));
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