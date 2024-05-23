#include <bits/stdc++.h>
using namespace std;

int Trie[1000010][26]{}, tot = 1;
int cnt[1000010]{};

void Insert(char *str)
{
    int len = strlen(str), p = 1;
    for (int i = 0; i < len; i++)
    {
        int ch = str[i] - 'a';
        if (Trie[p][ch] == 0)
            Trie[p][ch] = ++tot;
        p = Trie[p][ch];
    }
    ++cnt[p];
}

int Search(char *str)
{
    int len = strlen(str), p = 1;
    int ans = 0;
    for (int i = 0; i < len; i++)
    {
        p = Trie[p][str[i] - 'a'];
        if (p == 0)
            return ans;
        ans += cnt[p];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    char x[100010]{};
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        Insert(x);
    }
    while (m--)
    {
        cin >> x;
        cout << Search(x) << '\n';
    }
}