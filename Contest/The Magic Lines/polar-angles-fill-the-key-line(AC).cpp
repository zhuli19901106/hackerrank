#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int MAXN = 1111;
inline int sgn(double x) {
    return x < -eps ? -1 : x > eps;
}
struct P {
    int x,y;
    P(int x = 0, int y = 0) : x(x), y(y) {};
    int len2() const {
        return x * x + y * y;
    }
    //???v????????? [0,2*pi)
    double angle() const {
        double t = atan2(y,x);
        return sgn(t) >= 0 ? t : t + 2 * pi;
    }
    bool in() {
        return scanf("%d %d", &x, &y) == 2;
    }
    void out() const {
        printf("%d %d\n", x, y);
    }
} p[MAXN];

bool polarangle(const P& p1, const P& p2) {
    return sgn(p1.angle() - p2.angle()) == 0 ? sgn(p1.len2() - p2.len2()) <= 0 : sgn(p1.angle() - p2.angle()) < 0;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        p[i].in();
    }
    // ****FILL THE MISSING LINE HERE****
	sort(p, p + n, polarangle);
    for (int i = 0; i < n; i++) {
        p[i].out();
    }
}
