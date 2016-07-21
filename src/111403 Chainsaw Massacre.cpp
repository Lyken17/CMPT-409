#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

typedef long long ll;
using namespace std;


struct cpoint{
    ll x,y;
    cpoint() : x(0), y(0) {};
    cpoint(ll xx=0, ll yy=0) : x(xx), y(yy) {};
};

bool cmpX(cpoint p1, cpoint p2) {
    return p1.x < p2.x;
}

bool cmpY(cpoint p1, cpoint p2) {
    return p1.y < p2.y;
}

int main(int argc, char const *argv[]) {
    int times;
    cin >> times;
    while(times--) {
        vector<cpoint> pos;
        int l, w;
        cin >> l >> w;
        pos.push_back(cpoint(0,0));
        pos.push_back(cpoint(l,w));

        int k;
        while(1) {
            cin >> k;
            if (k == 0) break;

            int x, y, dx, dy;
            cin >> x >> y;
            pos.push_back(cpoint(x, y));
            if (k == 1) continue;
            cin >> dx >> dy;
            for (int i = 1; i < k; ++i) {
                x += dx;
                y += dy;
                pos.push_back(cpoint(x , y));
            }
        }


        // for (auto each : pos)
        //     cout << each.x << " " << each.y << endl;
        // cout << "--------------------" << endl;

        int n = pos.size();

        ll maxArea = 0;
        sort(pos.begin(), pos.end(), cmpX);
        for (int i = 0; i < n; i++) {
            ll lowerY = 0, upperY = w;

            for (int j = i+1; j < n; j++) {
                if (pos[i].x == pos[j].x)
                    continue;

                ll currArea = fabs(pos[i].x - pos[j].x) * (upperY - lowerY);
                maxArea = std::max(currArea, maxArea);

                if (pos[j].y < pos[i].y)
                    lowerY = std::max(lowerY, pos[j].y);
                else
                    upperY = std::min(upperY, pos[j].y);
            }
        }

        sort(pos.begin(), pos.end(), cmpY);
        for (int i = 0; i < n; ++i) {
            ll lowerX = 0, upperX = l;

            for(int j = i+1; j < n; ++j) {
                if (pos[i].y == pos[j].y)
                    continue;

                ll currArea = fabs(pos[i].y - pos[j].y) * (upperX - lowerX);
                maxArea = std::max(currArea, maxArea);

                if (pos[j].x < pos[i].x)
                    lowerX = std::max(lowerX, pos[j].x);
                else
                    upperX = std::min(upperX, pos[j].x);
            }
        }

        cout << maxArea << endl;
        // cout << "--------------------" << endl;
    }

    return 0;
}
