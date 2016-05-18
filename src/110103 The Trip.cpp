#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        if (n == 0) break;

        double arr[n];
        double temp;
        double avg = 0, res = 0;

        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            avg += arr[i];
        }

        avg /= n;

        double neg = 0, pos = 0;

        for (int i = 0; i < n; ++i) {
            temp = int((avg - arr[i]) * 100) / 100.0 ;
            if (temp < 0)
                neg -= temp;
            else
                pos += temp;
        }

        res = max(neg, pos);

//        for (int j = 0; j < n; ++j) {
//            printf ("$%.2lf\n", arr[j]);
//        }
        printf ("$%.2lf\n", res);
//        cout << "avg:" << avg <<  " res:" << res << endl << endl;
    }

    return 0;
}