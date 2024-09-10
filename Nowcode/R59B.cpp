//
// Created by 27682 on 2024/9/8.
//

#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

string a = "www.nowcoder.com", b = "ac.nowcoder.com";

inline void Zlin() {
    string x;
    cin >> x;

    for (int i = 0; i < x.length(); i++) {
        strncmp(x + i, a, 16);
    }
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}