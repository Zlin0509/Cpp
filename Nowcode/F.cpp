#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

struct Point
{
    int x, y;
    int index; // 用于标记点的原始索引
};

struct Slope
{
    int dx, dy;

    Slope(int _dx, int _dy)
    {
        int g = gcd(abs(_dx), abs(_dy));
        dx = _dx / g;
        dy = _dy / g;

        if (dy < 0)
        {
            dx = -dx;
            dy = -dy;
        }

        if (dx == 0)
            dy = 1;
        if (dy == 0)
            dx = 1;
    }

    bool operator==(const Slope &other) const
    {
        return dx == other.dx && dy == other.dy;
    }

    bool operator!=(const Slope &other) const
    {
        return !(*this == other);
    }
};

// 自定义哈希函数
struct SlopeHash
{
    size_t operator()(const Slope &s) const
    {
        return hash<int>()(s.dx) ^ (hash<int>()(s.dy) << 1);
    }
};

// 判断新点是否可以被插入
bool canFormNewLine(const Point &p, const unordered_set<Slope, SlopeHash> &slopes)
{
    for (const auto &s : slopes)
    {
        if (s == Slope(p.x, p.y))
        {
            return false;
        }
    }
    return true;
}

// 更新斜率集合
void updateSlopeSet(const Point &p, unordered_set<Slope, SlopeHash> &slopes, const vector<Point> &S)
{
    for (const auto &q : S)
    {
        Slope slope(p.x - q.x, p.y - q.y);
        slopes.insert(slope);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n * n);
    for (int i = 0; i < n * n; ++i)
    {
        cin >> points[i].x >> points[i].y;
        points[i].index = i; // 记录原始索引
    }

    vector<Point> S;
    unordered_set<Slope, SlopeHash> slopeSet(n * n); // 初始大小为 n^2

    vector<char> result(n * n, '0'); // 结果字符串初始化为全 '0'

    for (const auto &p : points)
    {
        if (canFormNewLine(p, slopeSet))
        {
            updateSlopeSet(p, slopeSet, S);
            S.push_back(p);
            result[p.index] = '1'; // 设置对应位置为 '1'
        }
    }

    cout << string(result.begin(), result.end()) << endl;

    return 0;
}