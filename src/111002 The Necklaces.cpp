#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

const int mx = 55;


struct edge {
    int from, to;
    edge(int u, int v) : from(u), to(v) {};
};

vector<edge> ans;
int start = 0;
int n;
int g[mx][mx], deg[mx];

void euler(int u)
{
    for (size_t v = 0; v < mx; v++) {
        if (g[u][v]) {
            --g[u][v], --g[v][u];
            euler(v);
            ans.push_back(edge(v, u)); // reverse!!@@!#^&*@!$^&!@^
            // cout << v << " " << u << endl;
        }
    }
}



int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    for (size_t cnt = 0; cnt < cases; cnt++) {
        memset(g, 0, sizeof(g));
        memset(deg, 0, sizeof(deg));
        ans.clear();

        cin >> n;
        int u, v;
        for (size_t i = 0; i < n; i++) {
            cin >> u >> v;
            ++g[u][v], ++g[v][u];
            ++deg[u], ++deg[v];
            start = u;
        }

        cout << "Case #" << cnt + 1 << endl;

        int i = 0;
        bool flag = true;
        for (i = 0; i < mx; ++i) {
            if (deg[i] & 1) break;
        }

        if (i < mx) {
            cout << "some beads may be lost" << endl;
        }
        else {
            euler(start);
            // cout << ans.size() << endl;
            for (auto each : ans)
                cout << each.from << " " << each.to << endl;
        }

        if (cnt < cases - 1)
            cout << endl;

    }

    return 0;
}
