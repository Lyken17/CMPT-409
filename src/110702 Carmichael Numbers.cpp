#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;

ll fast_mod(ll base, ll exponent, ll modulus) {
    ll result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % modulus;
        exponent >>= 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main(int argc, char const *argv[]) {
    ll n;
    set<ll> carmicheal = {561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973, 75361};
    while (cin >> n) {
        if (n == 0) break;
        auto it = carmicheal.find(n);
        if (it != carmicheal.end())
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;
    }
    return 0;
}

int another_main(int argc, char const *argv[]) {
    int n;

    bool prime[65000];
    for (size_t i = 0; i < 65000; i++)
        prime[i] = true;

    for (size_t i = 2; i < 30000; i++) { // 300 is a rought bound of sqrt(65000)
        if (prime[i]) {
            for (size_t j = 2 * i; j < 65000; j += i) {
                prime[j] = false;
            }
        }
    }


    while (cin >> n) {
        if (n == 0) break;

        bool flag = true;

        if (prime[n]) {
            cout << n << " is normal." << endl;
            continue;
        }

        for (size_t a = 2; a < n; a++) {
            int res = 0;
            // cout << "n: " << n << " a: " << a << endl;
            if (fast_mod(a, n, n) != a) {
                res = fast_mod(a, n, n);
                flag = false;
                // cout <<a << " " << res << endl;
                break;
            }
        }
        // cout << "Carmicheal test "  << flag << " and prime test " << prime[n] << endl;
        if (flag && prime[n] == false)
            cout << "The number " << n << " is a Carmichael number." << endl;
        else
            cout << n << " is normal." << endl;

    }

    return 0;
}
