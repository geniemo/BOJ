#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    int xpos;
    int ypos;
};


struct Bound
{
    Point cen;
    int radius;
};


bool InBound(Point p, Bound b)
{
    double distFromCen = sqrt( pow(p.xpos-b.cen.xpos, 2) + pow(p.ypos-b.cen.ypos, 2) );
    return (distFromCen <= b.radius);
}

int main(void)
{
    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n;
        Point startPoint;
        Point endPoint;
        int cnt = 0;

        cin >> startPoint.xpos >> startPoint.ypos;
        cin >> endPoint.xpos >> endPoint.ypos;
        cin >> n;
        Bound* boundaries = new Bound[n];
        for (int i = 0; i < n; i++)
        {
            cin >> boundaries[i].cen.xpos >> boundaries[i].cen.ypos >> boundaries[i].radius;
            // cnt + 1 if boundary contain only one
            cnt = (InBound(startPoint, boundaries[i]) != InBound(endPoint, boundaries[i])) ? cnt + 1 : cnt;
        }

        cout << cnt << endl;
        delete []boundaries;
    }  
    return 0;
}