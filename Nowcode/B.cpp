#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point
{
    double x, y;
};
// 计算两点之间的欧几里得距离
double distance(const Point &p1, const Point &p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
// 计算向量叉积
double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
// 使用旋转卡壳算法求凸包的直径（最远点对距离）
double rotatingCalipers(const vector<Point> &hull)
{
    int n = hull.size();
    if (n == 1)
        return 0.0;
    if (n == 2)
        return distance(hull[0], hull[1]);
    int k = 1;
    double maxDist = 0.0;
    for (int i = 0; i < n; ++i)
    {
        while (abs(cross(hull[i], hull[(i + 1) % n], hull[(k + 1) % n])) > abs(cross(hull[i], hull[(i + 1) % n], hull[k])))
        {
            k = (k + 1) % n;
        }
        maxDist = max(maxDist, distance(hull[i], hull[k]));
        maxDist = max(maxDist, distance(hull[(i + 1) % n], hull[k]));
    }
    return maxDist;
}