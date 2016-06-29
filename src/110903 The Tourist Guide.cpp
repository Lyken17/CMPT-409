#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(int argc, char const *argv[]) {
    int n, r;
    int cont = 1;

    while (cin >> n >> r) {
        if (n == 0 && r == 0) break;
        int map[n+1][n+1];

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                map[i][j] = -1;

        // read in and build graph
        for (int i = 0; i < r; ++i ) {
            int c1, c2, p;
            cin >> c1 >> c2 >> p;
            map[c1][c2] = map[c2][c1] = p;
        }

        int s, d, t;
        cin >> s >> d >> t;

        if (s == d) {
            cout << "Scenario #" << cont <<  endl << "Minimum Number of Trips = 0" << endl;
        }

        // bellman-ford
        for (size_t k = 1; k <= n; k++)
            for (size_t i = 1; i <= n; i++)
                for (size_t j = 1; j <= n; j++)
                    map[i][j] = max(map[i][j], min(map[i][k], map[k][j]));
        
        cout << "Scenario #" << cont <<  endl << "Minimum Number of Trips = " <<
                (t + map[s][d] - 2) / (map[s][d] - 1) << endl << endl;
        cont++;


    }

    return 0;
}
