#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll extended_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        ll r = extended_gcd(b, a % b, x, y);
        ll t = x;
        x = y;
        y = t - a / b * y;
        return r;
    }
}

int main(int argc, char const *argv[]) {
    ll n;
    ll c1, n1, c2, n2, x, y, m1, m2;

    while (cin >> n) {
        if (n == 0) break;

        cin >> c1 >> n1;
        cin >> c2 >> n2;
        ll temp = gcd(n1, n2);

        if (n % temp != 0) {
            cout << "failed" << endl;
            continue;
        }
        else {
            n /= temp;
            n1 /= temp;
            n2 /= temp;
        }
        // cout << "n : " << n << endl;
        // cout << "n1 : " << n1  << "  n2 : " << n2 << endl;
        // cout << "m1 : " << m1  << "  m2 : " << m2 << endl;

        // if (n <= n1 * n2 - n1 - n2) {
        //     // cout << "failed" << endl;
        //     cout << "failed by theory" << endl;
        //     continue;
        // }

        m1 = m2 = x = y = 0;
        extended_gcd(n1, n2, m1, m2);
        // cout << "n : " << n << endl;
        // cout << "n1 : " << n1  << "  n2 : " << n2 << endl;
        // cout << "m1 : " << m1  << "  m2 : " << m2 << endl;

        m1 *= n;
        m2 *= n;

        ll low = ceil(-m1 / double(n2)), upper = floor(m2 / double(n1));
        ll cost = c1 * n2 - c2 * n1;

        if (low <= upper) {
            ll t;
            if (cost * low < cost * upper) {
                t = low;
            }
            else {
                t = upper;
            }
            x = m1 + n2 * t;
            y = m2 - n1 * t;

            cout << x << " " << y << endl;
        }
        else {
            cout << "failed" << endl;
            // cout << "failed by bound" << endl;
        }
        // if (c1 / double(n1) < c2 / double(n2)) {
        //     x1 += n / n1;
        //     n = n % n1;
        //     y1 += n / n2;
        //     n = n % n2;
        // }
        // else {
        //     y1 += n / n2;
        //     n = n % n2;
        //     x1 += n / n1;
        //     n = n % n1;
        // }
        // x1 += n * x;
        // y1 += n * y;
        //
        // if (n != 0) {
        //     if (x1 < 0) {
        //         ll exchange = floor((0 - x1) / n2);
        //         x1 += exchange * n2;
        //         y1 -= exchange * n1;
        //     }
        //     if (y1 < 0) {
        //         ll exchange = floor((0 - y1) / n1);
        //         y1 += exchange * n1;
        //         x1 -= exchange * n2;
        //     }
        // }
        // cout << x1 << " " << y1 << endl;


    }
    return 0;
}
