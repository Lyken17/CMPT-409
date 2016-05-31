#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int bef, cur;
        cin >> bef;

        bool flag = true;
        bool jolly[n];

        for (int i = 0; i < n; ++i)
            jolly[i] = false;

        for (int i = 1; i < n; ++i) {
            cin >> cur;

            int diff = abs(cur - bef);
            if (diff < 1 || diff > n - 1 || jolly[diff])
                flag = false;

            jolly[diff] = true;
            bef = cur;
        }

        if (flag)
            cout << "Jolly" << endl;
        else
            cout << "Not jolly" << endl;
    }
}
