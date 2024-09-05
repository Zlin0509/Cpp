#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;
int nn;
void deter(vector<int> nums)
{
    int maxnum = *max_element(nums.begin(), nums.end());
    vector<int> hasnum(maxnum + 1, false);
    for (auto n : nums)
        hasnum[n] = true;
    int count = 0;
    for (int g = 1; g <= maxnum; g++)
    {
        int gcd = -1;
        for (int num = g; num <= maxnum; num += g)
        {
            if (hasnum[num])
            {
                if (gcd == -1)
                    gcd = num;
                else
                    gcd = __gcd(num, gcd);
                if (gcd <= g)
                    break;
            }
        }
        if (gcd == g)
            count++;
    }
    count -= nn;
    cout << (count & 1 ? "dXqwq" : "Haitang") << '\n';
}

inline void Zlin()
{
    cin >> nn;
    vector<int> nums(nn);
    for (int i = 0; i < nn; ++i)
        cin >> nums[i];
    if (nn == 1)
        cout << "Haitang" << '\n';
    else
        deter(nums);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ttt;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}