#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include <iomanip>

using namespace std;
const double eps = 1e-8;


int dcmp(double x) {
    if (fabs(x) < eps) return 0;
    else return x < 0 ? - 1 : 1;
}

struct Point {
    double x, y;
    Point() : x(0), y(0) {}
    Point(double xx, double yy) : x(xx), y(yy) {}
    bool operator < (const Point &temp) const {
        return (x < temp.x || (dcmp(x - temp.x))) == 0 && y < temp.y;
    }
    Point operator + (const Point &A) const {
        return Point(x + A.x, y + A.y);
    }
    Point operator - (const Point &A) const {
        return Point(x - A.x, y - A.y);
    }
    Point operator * (double p) const{
    	return Point(x * p, y * p);
    }
};

typedef Point Vector;

Vector Rev(Vector A){
	return Vector(-A.y, A.x);
}

Point Mid(Point A, Point B){
	return Point((A.x + B.x) * 0.5, (A.y + B.y) * 0.5);
}

double dot(Vector A, Vector B){
	return A.x * B.x + A.y * B.y;
}

double det(Vector A, Vector B){
	return A.x * B.y - A.y * B.x;
}

struct Line {
    Point P;
    Vector v;
    Line() {}
    Line(Point PP, Vector vv) : P(PP), v(vv) {}
};

bool OnLeft(Line l, Point p) {
    return det(l.v, p - l.P) > 0;
}

typedef vector<Point> Polygon;

Point GetIntersection(Point A, Vector v, Point B, Vector w) {
    Vector u = A - B;
    double t = det(w, u) / det(v, w);
    return A + v * t;
}

bool OnSegment(Point P, Point A, Point B) {
    return dcmp(det(A - P, B - P)) == 0 && dcmp(dot(A - P, B - P)) < 0;
}

double Area(Polygon &p) {
    double S = 0.0;
    if (p.size() <= 1) return 0.0;
    for(int i=1; i<p.size()-1; i++){
		S += det(p[i]-p[0], p[i+1]-p[0]);
	}
	return fabs(S) * 0.5;
}

Polygon Cut(Polygon p, Line L) {
    Polygon newpoly;
    int n = p.size();

    for (int i = 0; i < n; ++i) {
        Point C = p[i];
        Point D = p[(i + 1) % n];
        if (dcmp(det(L.v, C - L.P)) >= 0) newpoly.push_back(C);
        if (dcmp(det(L.v, C - D) != 0))  {
            Point ip = GetIntersection(L.P, L.v, C, D - C);
            if (OnSegment(ip, C, D)) {
                newpoly.push_back(ip);
            }
        }
    }
    return newpoly;
}

bool Same(Point A, Point B) {
    return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y)==0;
}

int main() {
    Polygon p;
    p.push_back(Point(0.0, 0.0));
    p.push_back(Point(10.0, 0.0));
    p.push_back(Point(10.0, 10.0));
    p.push_back(Point(0.0, 10.0));
    double x, y;
    string s;
    bool flag = false;
    Point p0(0.0, 0.0);
    Point p1;
    while (cin >> x >> y >> s) {
        if (s == "Same") {
            flag = true;
        }
        if (flag) {
            cout << "0.00" << endl;
            continue;
        }
        p1 = Point(x, y);
        Vector v = Rev(p1 - p0);
        Line L = Line(Mid(p0, p1), v);
        if (OnLeft(L, p0)) {
            if (s == "Hotter") {
                L.v = L.v * (-1.0);
            }
        }
        else {
            if (s == "Colder") {
                L.v = L.v * (-1.0);
            }
        }
        p = Cut(p, L);
        double S = Area(p);
        p0 = p1;
        cout << setiosflags(ios::fixed) << std::setprecision(2) << S << endl;
        // printf("%.2lf\n", S);
    }
}
