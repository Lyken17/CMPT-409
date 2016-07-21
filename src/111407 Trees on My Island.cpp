#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

typedef long long ll;
const double eps = 1e-8;
const double pi = acos(-1.0);
const double maxl = 10;

struct cpoint{
    ll x,y;
    cpoint() : x(0), y(0) {};
    cpoint(ll xx=0, ll yy=0) : x(xx), y(yy) {};
};

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

//sample test passed
double PolygonArea(const vector<cpoint> &p) {
    int n = p.size();
    if (n < 3) return 0;
    double s = p[0].y * (p[n - 1].x - p[1].x);
    for (int i = 1; i < n; ++i)
        s += p[i].y * (p[i - 1].x - p[(i + 1) % n].x);
    return fabs(s / 2);
}

//sample test passed
ll LatticeOnBoundary(cpoint p1, cpoint p2) {
    ll L = fabs(p1.x - p2.x), D = fabs(p1.y - p2.y);
    if (L == 0 || D == 0) {
        return L == 0 ? D : L;
    }
    else
        return gcd(L, D);
}

ll PolygonBoundaryLattices(const vector<cpoint> &p) {
    ll n = p.size();
    ll total = LatticeOnBoundary(p[n-1], p[0]);
    for (int i = 1; i < n; ++i) {
        total += LatticeOnBoundary(p[i-1], p[i]);
    }
    return total;
}

int temp_main(int argc, char const *argv[]) {
    cpoint p1(0,0), p2(5,7);
    vector<cpoint> temp;
    temp.push_back(cpoint(0,0));
    temp.push_back(cpoint(2,0));
    temp.push_back(cpoint(3,2));
    temp.push_back(cpoint(1,2));
    cout << PolygonBoundaryLattices(temp) << endl;
    return 0;
}

int main(int argc, char const *argv[]) {

    int n;
    while (cin >> n) {
        if (n == 0) break;

        int x, y;
        vector<cpoint> polygon;
        for (size_t i = 0; i < n; i++) {
            cin >> x >> y;
            polygon.push_back(cpoint(x, y));
        }

        double A = PolygonArea(polygon);
        ll b = PolygonBoundaryLattices(polygon);
        ll inside = A - b / 2.0 + 1;
        cout << inside << endl;
    }
    return 0;
}
