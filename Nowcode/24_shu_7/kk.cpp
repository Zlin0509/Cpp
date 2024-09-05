#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countSequences(const string &S, const string &T)
{
    int n = S.size();
    int m = T.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // 初始化 dp[0][0] = 1
    dp[0][0] = 1;

    // 填充 DP 表
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j]; // 不添加 S[i-1]
            if (j > 0 && S[i - 1] == T[j - 1])
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD; // 添加 S[i-1]
            }
        }
    }

    // 结果是 dp[n][m]
    return dp[n][m];
}

int main()
{
    int n, m;
    string S, T;
    cin >> n >> m;
    cin >> S >> T;
    cout << countSequences(S, T) << endl;
    return 0;
}