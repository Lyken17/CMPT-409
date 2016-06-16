#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b , a % b);
}

bool is_prime(ll number)
{
    if (number == 2)
        return true;

    if (number % 2 == 0)
        return false;

    for (ll c = 3; c <= ceil(sqrt(number)); c += 2)
        if (number % c == 0)
            return false;

    return true;
}


int main(int argc, char const *argv[]) {
    int n, m;
    while (cin >> n >> m) {
        // n! % m = 0 ?
        int nn = n, mm = m;
        bool divided = false;

        if (m == 1) {
            divided =  true;
        }
        else if (m == 0) {
            divided = false;
        }
        else if (m > n && is_prime(m)) {
            divided = false;
        }
        else if (m <= n) {
            divided = true;
        }
        else {
            while(n > 1) {
                ll temp = gcd(m, n);
                n -= 1;
                if (temp > 1) {
                    m /= temp;
                    if (m <= n) {
                        divided = true;
                        break;
                    }

                    if (is_prime(m)) {
                        divided = false;
                        break;
                    }
                }
            }
        }

        if (divided)
            cout << mm << " divides " << nn << "!" << endl;
        else
            cout << mm << " does not divide " << nn << "!" << endl;
    }

    return 0;
}
