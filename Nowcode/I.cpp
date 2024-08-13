#include "bits/stdc++.h"
using namespace std;
vector<int> add(vector<int> &A, vector<int> &B)
{
    if (A.size() < B.size())
        return add(B, A);

    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t /= 10;
    }
    if (t)
        C.push_back(t);
    return C;
}
vector<int> mul(vector<int> &A, vector<int> &B)
{

    vector<int> C(A.size() + B.size(), 0);
    int t = 0;
    for (int i = 0; i < B.size(); i++)
    {
        int k = 0;
        for (int j = 0; j < A.size() || t; j++)
        {
            if (j < A.size())
            {
                t += (A[j] * B[i] + C[i + j]);
                C[i + j] = t % 10;
                t /= 10;
                k = i + j;
            }

            else
            {
                k++;
                C[k] = t;
                t = 0;
            }
        }
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
vector<int> divv(vector<int> &A, int b, int r)
{
    vector<int> C;
    for (int i = A.size() - 1; i >= 0; --i)
    {
        r = r * 10 + A[i];
        C.push_back(r / b);
        r %= b;
    }
    reverse(C.begin(), C.end());
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
bool cmp(vector<int> &A, vector<int> &B)
{
    while (A.size() > 1 && A.back() == 0)
        A.pop_back();
    while (B.size() > 1 && B.back() == 0)
        B.pop_back();
    if (A.size() != B.size())
        return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i])
            return A[i] > B[i];
    return true;
}
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        t = A[i] - t;
        if (i < B.size())
            t -= B[i];
        C.push_back((t + 10) % 10);
        if (t >= 0)
            t = 0;
        else
            t = 1;
    }
    while (C.size() > 1 && C.back() == 0)
        C.pop_back();
    return C;
}
bool cmp2(vector<int> &A, vector<int> &B)
{
    while (A.size() > 1 && A.back() == 0)
        A.pop_back();
    while (B.size() > 1 && B.back() == 0)
        B.pop_back();
    if (A.size() != B.size())
        return A.size() < B.size();
    for (int i = A.size() - 1; i >= 0; --i)
        if (A[i] != B[i])
            return A[i] < B[i];
    return true;
}
bool check(vector<int> a, vector<int> b)
{
    vector<int> z = mul(a, a);
    return cmp(z, b);
}
bool css(vector<int> a, vector<int> b)
{
    vector<int> z = mul(a, a);
    return cmp2(z, b);
}
void output(vector<int> a)
{
    reverse(a.begin(), a.end());
    for (auto it : a)
        cout << it;
    cout << '\n';
}
int n;
char c;
vector<int> xa, xb, ya, yb;
vector<int> ans;
vector<int> midsearch(vector<int> a1, vector<int> a2, vector<int> b1, vector<int> b2)
{
    vector<int> x1, x2, y1, y2;
    vector<int> l, r, mid, z;
    vector<int> zz;
    zz.push_back(1);
    l.push_back(0);
    for (int i = 1; i <= n / 2; i++)
        r.push_back(0);
    if (!(n / 2))
        r.push_back(0);
    r.push_back(1);
    while (cmp(r, l) && r != l)
    {
        z = add(l, r);
        mid = divv(z, 2, 0);
        if (check(mid, a1))
            r = mid;
        else
            l = add(mid, zz);
    }
    x1 = l;
    z = mul(x1, x1);
    bool check1 = 0, check2 = 0;
    if (z == a1)
    {
        l.clear(), r.clear();
        l.push_back(0);
        for (int i = 1; i <= n / 2; i++)
            r.push_back(0);
        if (!(n / 2))
            r.push_back(0);
        r.push_back(1);
        while (cmp(r, l) && r != l)
        {
            z = add(l, r);
            mid = divv(z, 2, 0);
            if (check(mid, a2))
                r = mid;
            else
                l = add(mid, zz);
        }
        x2 = l;
    }
    else
        check1 = 1, x2.push_back(0);

    l.clear(), r.clear();
    l.push_back(0);
    for (int i = 1; i <= n / 2; i++)
        r.push_back(0);
    if (!(n / 2))
        r.push_back(0);
    r.push_back(1);
    while (cmp(r, l) && r != l)
    {
        z = add(l, r);
        z = add(z, zz);
        mid = divv(z, 2, 0);
        if (css(mid, b1))
            l = mid;
        else
            r = sub(mid, zz);
    }
    y1 = l;
    z = mul(y1, y1);
    if (z == b1)
    {
        l.clear(), r.clear();
        l.push_back(0);
        for (int i = 1; i <= n / 2; i++)
            r.push_back(0);
        if (!(n / 2))
            r.push_back(0);
        r.push_back(1);
        while (cmp(r, l) && r != l)
        {
            z = add(l, r);
            z = add(z, zz);
            mid = divv(z, 2, 0);
            if (css(mid, b2))
                l = mid;
            else
                r = sub(mid, zz);
        }
        y2 = l;
    }
    else
        check2 = 1, y2.push_back(0);

    vector<int> tot, xx;
    for (int i = 1; i <= n / 2; i++)
        xx.push_back(0);
    xx.push_back(1);
    xx = sub(xx, zz);
    l.clear(), r.clear();
    l.push_back(1);
    for (int i = 1; i <= n / 2; i++)
        r.push_back(0);
    if (!(n / 2))
        r.push_back(0);
    r.push_back(1);
    while (cmp(r, l) && r != l)
    {
        z = add(l, r);
        z = add(z, zz);
        mid = divv(z, 2, 0);
        if (css(mid, xx))
            l = mid;
        else
            r = sub(mid, zz);
    }
    tot = l;
    tot = add(tot, zz);
    // output(x1);
    // output(x2);
    // output(y1);
    // output(y2);
    vector<int> ans;
    z = sub(y1, x1);
    z = sub(z, zz);
    ans = mul(z, tot);
    if (check1)
        ans = add(ans, tot);
    else
    {
        z = sub(tot, x2);
        ans = add(ans, z);
    }
    if (check2)
        ans = add(ans, tot);
    else
    {
        ans = add(ans, y2);
        ans = add(ans, zz);
    }
    return ans;
}
inline void Zlin()
{
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> c;
        xa.push_back(c - '0');
    }
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> c;
        xb.push_back(c - '0');
    }
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> c;
        ya.push_back(c - '0');
    }
    for (int i = 1; i <= n / 2; i++)
    {
        cin >> c;
        yb.push_back(c - '0');
    }
    reverse(xa.begin(), xa.end());
    reverse(xb.begin(), xb.end());
    reverse(ya.begin(), ya.end());
    reverse(yb.begin(), yb.end());

    ans = midsearch(xa, xb, ya, yb);

    output(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Zlin();
}