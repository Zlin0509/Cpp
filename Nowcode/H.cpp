#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
const double tt = 3.141592652589;
struct Point
{
    double x, y;
    bool operator<(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};
double distSquared(const Point &p1, const Point &p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double cross(const Point &O, const Point &A, const Point &B)
{
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}
vector<Point> convexHull(vector<Point> &points)
{
    int n = points.size(), k = 0;
    if (n <= 1)
        return points;
    vector<Point> hull(2 * n);
    sort(points.begin(), points.end());
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--;
        hull[k++] = points[i];
    }

    // 构建上半部分凸包
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--;
        hull[k++] = points[i];
    }

    hull.resize(k - 1);
    return hull;
}
double rotatingCalipers(const vector<Point> &hull)
{
    int n = hull.size();
    if (n == 1)
        return 0;
    if (n == 2)
        return distSquared(hull[0], hull[1]);

    double maxDist = 0;
    int j = 1;
    for (int i = 0; i < n; ++i)
    {
        while (abs(cross(hull[i], hull[(i + 1) % n], hull[j])) < abs(cross(hull[i], hull[(i + 1) % n], hull[(j + 1) % n])))
        {
            j = (j + 1) % n;
        }
        maxDist = max(maxDist, distSquared(hull[i], hull[j]));
        maxDist = max(maxDist, distSquared(hull[(i + 1) % n], hull[j]));
    }
    return maxDist;
}
inline void Zlin()
{
    int n, m;
    vector<Point> p1(n), p2(m);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p1[i].x >> p1[i].y;
    cin >> m;
    for (int i = 0; i < n; ++i)
        cin >> p2[i].x >> p2[i].y;
    vector<Point> hull = convexHull(p2);
    double maxDistSquared = rotatingCalipers(hull);
    cout << "最远点对的距离为: " << sqrt(maxDistSquared) << endl;
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