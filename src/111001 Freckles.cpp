#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct pos{
    double x, y;
};

struct edge{
    int p1, p2;
    double length;
    bool operator < (const edge &t) const {
        return length < t.length;
    }
};

inline double distance(pos p1, pos p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int uni[200];

int union_find(int p) {
    return p == uni[p] ? p : (uni[p] = union_find(uni[p]));
}

int main(int argc, char const *argv[]) {
    int times;
    cin >> times;
    while(times--)
    {
        int n;
        cin >> n;


        pos arr[n];
        double dis[n][n];
        vector<edge> edges;

        for (int i = 0; i < n; i++) {
            cin >> arr[i].x >> arr[i].y;
            uni[i] = i;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // build distance map
                if (i == j) {dis[i][j] = 0; continue;}
                if (i > j) continue;
                double temp = distance(arr[i], arr[j]);
                dis[i][j] = dis[j][i] = temp;
                edges.push_back((edge){i, j, temp});
            }
        }

        sort(edges.begin(), edges.end());

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << dis[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        // cout << "=====================" << endl;
        // for (int i = 0; i < edges.size(); i++) {
        //     cout <<std::setw(10) <<  edges[i].length << "  |   " << edges[i].p1 << " " << edges[i].p2  << endl ;
        // }

        int m = n;
        double total = 0;
        int pt = 0;
        while (m > 0 && 2 * pt < n * (n - 1))
        {
            edge temp = edges[pt]; pt++;

            int s1 = union_find(temp.p1), s2 = union_find(temp.p2);
            if (s1 == s2) continue; // leads to cycle

            uni[s1] = uni[s2] = min(s1, s2);
            total += temp.length;
            m--;
        }
        // cout << "pt : "  << pt << " m : " << m << endl;
        cout << std::fixed << std::setprecision(2) << total << endl;
        if (times != 0)
            cout << endl;

    }

    return 0;
}
