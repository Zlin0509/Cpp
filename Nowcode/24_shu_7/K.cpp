#include "bits/stdc++.h"
using namespace std;

const long long mod = 1e9 + 7;

int count(const string &s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 空子序列

    unordered_map<char, int> last;

    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1] * 2;
        if (last.find(s[i - 1]) != last.end())
        {
            dp[i] -= dp[last[s[i - 1]] - 1];
        }
        last[s[i - 1]] = i;
    }

    return dp[n] - 1; // 减去空子序列
}
bool isPalindrome(const string &s)
{
    int left = 0;
    int right = s.size() - 1;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

bool hasPalindromeSuffixOfLength2OrMore(const string &s)
{
    int n = s.size();
    for (int i = n - 2; i >= 0; --i)
    {
        string suffix = s.substr(i);
        if (suffix.size() >= 2 && isPalindrome(suffix))
        {
            return true;
        }
    }
    return false;
}

inline void Zlin()
{
    string s, t, a;
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    cin >> s >> t;

    int ll = 0, rr = 0, l, r;
    while (rr < t.length() && ll <= s.length())
    {
        while (ll < s.length() && s[ll] != t[rr])
            ++ll;
        ++ll;
        ++rr;
    }
    l = ll - 1;
    ll = s.length() - 1, rr = 0;
    while (rr < t.length() && ll >= -1)
    {
        while (ll >= 0 && s[ll] != t[rr])
            --ll;
        --ll;
        ++rr;
    }
    r = ll + 1;
    if (l == s.length() || r == -1)
    {
        cout << 0;
        return;
    }
    int cnt = 1;
    for (int i = t.length() - 1; i >= 0; i--)
    {
        if (t[i] != t[i - 1])
            break;
        ++cnt;
    }
    cnt = min(cnt, m - 1);
    if (l + 1 <= r)
    {
        for (int i = l + 1; i < r; i++)
            a += s[i];
        ans = count(a) + cnt + 1;
        // cout << ans << '\n';
        if (hasPalindromeSuffixOfLength2OrMore(t) || m == 1)
            ++ans;
    }
    else
    {
        int tag = 0;
        for (int i = 0; i < r; i++)
            if (s[i] == t[tag])
                ++tag;
        ll = tag, rr = m - 1;
        bool check = 1;
        if (tag == 0)
            check = 0;
        while (ll < rr)
        {
            if (t[ll++] != t[rr--])
            {
                check = 0;
                break;
            }
        }
        check ? ans = 1 : ans = 0;
        if (cnt >= m - tag)
            ans = cnt - m + tag + 1;
        ll = 0, rr = m - 1;
        check = 1;
        while (ll < rr)
        {
            if (t[ll++] != t[rr--])
            {
                check = 0;
                break;
            }
        }
        if (check)
            ++ans;
    }

    cout << ans % mod;
}
int main()
{
    Zlin();
}