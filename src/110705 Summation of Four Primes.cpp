#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

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
    ll n;
    while (cin >> n) {
        if (n < 8) {
            cout << "Impossible." << endl;
            continue;
        }

        if (n & 1) {
            cout << "2 3 ";
            n -= 5;
        }
        else {
            cout << "2 2 ";
            n -= 4;
        }
        
        for (ll i = 2; i <= n / 2; i++) {
            if (is_prime(i) && is_prime(n - i)) {
                cout << i << " " << n - i << endl;
                break;
            }
        }
    }
    return 0;
}
