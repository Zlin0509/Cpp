#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e7;
ll ss[N + 10]{};
void dd()
{
    for (int i = 2; i <= N; i++)
    {
        if (!ss[i])
            for (int j = 2; j * i <= N; j++)
                if (!ss[i * j])
                    ss[i * j] = i;
    }
}

void ffa()
{
    ll a, b;
    ll s = 0;
    cin >> a >> b;
    if (a == b)
    {
        cout << 0;
        return;
    }
    if (b % a == 0)
    {
        cout << b;
        return;
    }
    if (gcd(a, b) != 1)
    {
        cout << a + b;
        return;
    }
    if (ss[a] && ss[b])
    {
        if (ss[a] * ss[b] <= 2 * (ss[a] + ss[b]))
        {
            s = a + b + ss[a] * ss[b];
        }
        else
        {
            s = a + b + 2 * (ss[a] + ss[b]);
        }
        cout << s;
    }
    else
    {
        if (ss[a])
        {
            s += a;
            if (ss[a] * b <= 2 * (ss[a] + b))
            {
                s += ss[a] * b;
            }
            else
            {
                s += 2 * (ss[a] + b);
            }
        }
        else if (ss[b])
        {
            s += b;
            if (ss[b] * a <= 2 * (ss[b] + a))
            {
                s += ss[b] * a;
            }
            else
            {
                s += 2 * (ss[b] + a);
            }
        }
        else
        {
            if (a * b <= 2 * (a + b))
            {
                s += a * b;
            }
            else
            {
                s += 2 * (a + b);
            }
        }
        cout << s;
    }
}
int main()
{
    int n;
    cin >> n;
    dd();
    while (n--)
    {
        ffa();
        cout << '\n';
    }
}