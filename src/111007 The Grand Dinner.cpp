#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

struct cmpt {
    int id, num;
    bool operator < (const cmpt &t) const {
        return num > t.num;
    }
};

int main(int argc, char const *argv[]) {
    int m, n;
    string line;
    while(cin >> m >> n) {
        if (m == 0 && n == 0) break;

        string line;
        cmpt team[m], table[n];
        int arrange[m][n];

        int total = 0;
        bool flag = true;

        for (size_t i = 0; i < m; i++) {
            cin >> team[i].num;
            team[i].id = i + 1;
            total += team[i].num;

            if (team[i].num > n) {
                flag = false;
            }
        }
        for (size_t i = 0; i < n; i++) {
            cin >> table[i].num;
            table[i].id = i + 1;
            total -= table[i].num;
        }

        if (total > 0 || flag == false) {
            cout << 0 << endl;
            continue;
        }

        stringstream output;

        flag = true;
        sort(table, table + n);

        // greedy choose
        for (int i = 0; i < m && flag; ++i) {
            sort(table, table + n);
            for (int j = 0; j < team[i].num && flag; ++j) {
                if (table[j].num == 0) {
                    flag = false;
                    break;
                }
                output << table[j].id << " ";
                table[j].num -= 1;
            }
            output << endl;
        }

        if (flag) {
            cout << 1 << endl;
            cout << output.str();
        } else {
            cout << 0 << endl;
        }

    }
    return 0;
}
