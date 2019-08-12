#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
const double eps = 1e-8;

int sgn(double x) {
    if(fabs(x) < eps)
		return 0;
    if(x < 0)
		return -1;
    else 
		return 1;
}
struct Point {
    double x, y;
    Point() {};
    Point(double _x, double _y) {
        x = _x, y = _y;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    Point operator - (const Point &b)const {
        return   Point (x - b.x, y - b.y);
    }
    double  operator ^ (const Point &b)const {
        return x * b.y - y * b.x;
    }
};
int main() {
    Point a, b, c;
    a.input();
    b.input();
    c.input();
    Point ab, cb;
    ab = Point(a - b);
    cb = Point(c - b);
    if(sgn(ab ^ cb) == 0) {
        printf("You're so funny\n");
    }
    else {
        printf("%.2lf\n", fabs(ab ^ cb) / 2);
    }
}


