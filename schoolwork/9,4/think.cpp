#include "bits/stdc++.h"

using namespace std;

const int n = 7, m = 13;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char c[5] = {'d', 'a', 's', 'w'};

string a[10];
int used[n + 1][m + 1];
vector <stack<int>> ans;
stack<int> now;

inline void dfs(int x, int y) {
    if (a[x][y] == 'O') {
        stack<int> nn = now, nnn;
        while (!nn.empty()) nnn.push(nn.top()), nn.pop();
        ans.push_back(nnn);
        return;
    }
    for (int i = 0, xx, yy; i < 4; i++) {
        xx = x + dx[i], yy = y + dy[i];
        if (xx > n || xx < 1 || yy > m || yy < 1 || used[xx][yy] || a[xx][yy] == 'A')
            continue;
        now.push(i), ++used[xx][yy];
        dfs(xx, yy);
        now.pop(), --used[xx][yy];
    }
}

bool cmp(const stack<int> a, const stack<int> b) {
    return a.size() < b.size();
}

inline void Zlin() {
    int x = 1, y = 3;
    for (int i = 1; i <= n; i++) {
        getline(cin, a[i]);
        a[i] = ' ' + a[i];
    }
    ++used[x][y];
    dfs(x, y);
    sort(ans.begin(), ans.end(), cmp);
    cout << "所有情况：\n";
    for (auto it: ans) {
        while (!it.empty()) {

            cout << c[it.top()] << ' ';
            it.pop();
        }
        cout << '\n';
    }
    now = ans[0];
    cout << "最短路径为：\n";
    while (!now.empty()) {
        x += dx[now.top()], y += dy[now.top()];
        cout << c[now.top()] << ' ';
        now.pop();
        a[x][y] = 'X';
    }
    cout << '\n';
    cout << "可视化为:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << a[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    Zlin();
}
