#include <iostream>
#include <vector>
using namespace std;

// 生成满足条件的排列
vector<int> generatePermutation(int n, int m)
{
    vector<int> permutation(n);

    // 用升序排列初步构造排列
    for (int i = 0; i < n; ++i)
    {
        permutation[i] = i + 1;
    }

    // 我们从升序排列出发，构造具体的排列
    // 根据 m 的要求调整排列，使得恰好有 m 个有效的三角形子区间
    // 使用的方法：调整最后几个元素以达到 m 个三角形

    // 例如，可以调整排列使得最后 m 个子区间是三角形，其它不是
    // 交换操作的一个简单实现（具体调整需要详细设计）
    int triangle_count = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        if (triangle_count < m)
        {
            // Swap to create a valid triangle
            swap(permutation[i], permutation[i + 2]);
            triangle_count++;
        }
    }

    // Return the resulting permutation
    return permutation;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<int> permutation = generatePermutation(n, m);

        for (int i = 0; i < n; ++i)
        {
            cout << permutation[i] << " ";
        }
        cout << endl;
    }

    return 0;
}