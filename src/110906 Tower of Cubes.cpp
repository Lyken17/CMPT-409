/*
    Following code has passed Uva test, but failed programming-challenges.
    Have no idea why.
*/

#include <iostream>
#include <string>

using namespace std;

string face[6] = {"front", "back", "left", "right", "top", "bottom"};


inline int rev(int n) {
    return n & 1 ? n - 1 : n + 1;
}

void rec_print(int k, int *pre ) {
    if (k == -1)
        return;
    rec_print(pre[k], pre);
    cout << k / 6 + 1<< " " << face[k % 6] << endl;
}



int main(int argc, char const *argv[]) {
    int n;
    int cnt = 1;

    while (cin >> n) {
        if (n == 0) break;
        if (cnt != 1)
            cout << endl;
        int color[n][6];

        int dp[n * 6],
            pre[n * 6],
            top[n * 6],
            bot[n * 6],
            lev[n * 6];

        for (size_t i = 0; i < n * 6; i++) {
            dp[i] = 0;
            pre[i] = - 1;
        }

        // read in
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < 6; j++) {
                cin >> color[i][j];
            }
            for (size_t j = 0; j < 6; j++) {
                int index = i * 6 + j;
                top[index] = color[i][j];
                bot[index] = color[i][rev(j)];
                lev[index] = i + 1;
            }
        }

        // dp
        int max_dep = 0, max_pos = 0;
        for (size_t i = 0; i < n * 6; i++) {
            for (size_t j = i + 1; j < n * 6; j++) {
                if (lev[j] > lev[i] && bot[i] == top[j] && dp[j] < dp[i] + 1) {
                    dp[j] = dp[i] + 1;
                    pre[j] = i;
                }
                if (dp[i] > max_dep) {
                    max_dep = dp[i];
                    max_pos = i;
                }
            }
        }

        cout << "Case #" << cnt << endl;
        cout << max_dep + 1 << endl;
        rec_print(max_pos, pre);

        cnt++;

    }
    return 0;
}
