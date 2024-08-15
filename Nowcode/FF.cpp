#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <numeric>

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

        // 确保斜率的方向一致，dy 为非负值
        if (dy < 0)
        {
            dx = -dx;
            dy = -dy;
        }
        else if (dy == 0)
        {
            dx = (dx > 0) ? 1 : -1;
        }
    }

    bool operator<(const Slope &other) const
    {
        return tie(dx, dy) < tie(other.dx, other.dy);
    }
};

// 判断新点是否与已存在点共线
bool canFormNewLine(const Point &p, const vector<Point> &S, set<Slope> &slopes)
{
    for (const auto &q : S)
    {
        Slope slope(p.x - q.x, p.y - q.y);
        if (slopes.find(slope) != slopes.end())
        {
            return false;
        }
    }
    return true;
}

// 更新斜率集合
void updateSlopeSet(const Point &p, set<Slope> &slopes, const vector<Point> &S)
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

    vector<Point> S;     // 已经添加的点
    set<Slope> slopeSet; // 记录斜率的集合

    vector<char> result(n * n, '0'); // 结果字符串初始化为全 '0'

    for (const auto &p : points)
    {
        if (canFormNewLine(p, S, slopeSet))
        {
            updateSlopeSet(p, slopeSet, S);
            S.push_back(p);
            result[p.index] = '1'; // 设置对应位置为 '1'
        }
    }

    cout << string(result.begin(), result.end()) << endl;

    return 0;
}