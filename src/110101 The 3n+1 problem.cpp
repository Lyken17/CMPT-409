#include <iostream>
#include <map>

using namespace std;


unsigned long getMaxCycle(unsigned long a);
unsigned long getMaxCycleBetween(unsigned long a, unsigned long b);
map<unsigned long, unsigned long> cycleTimes;


int main()
{
    int a, b;

    while (cin >> a >> b) {
        unsigned long maxCycle = getMaxCycleBetween(min(a,b), max(a,b));
        cout << a << " " << b << " " << maxCycle << endl;
    }
}

unsigned long getMaxCycle(unsigned long a)
{
    if ( a == 0) return 0;

    unsigned long cycle = 1;

    while (a != 1) {
        if (a % 2 == 0) {
            a /= 2;
        } else {
            a = 3 * a + 1;
        }
        cycle++;
    }

    return cycle;
}

unsigned long recurFind(unsigned long n) {
    auto it = cycleTimes.find(n);
    if (it == cycleTimes.end()) {
        if (n == 0 || n == 1) {
            cycleTimes[n] = n;
        }
        else {
            if (n % 2 == 0) {
                cycleTimes[n] = recurFind(n / 2) + 1;
            }
            else {
                cycleTimes[n] = recurFind(3 * n + 1) + 1;
            }
        }
    }
    return cycleTimes[n];
}

unsigned long getMaxCycleBetween(unsigned long a, unsigned long b)
{
    unsigned long maxCycle = 0;

    for (unsigned long i = a; i <= b; ++i) {
        unsigned long cycle = recurFind(i);
        maxCycle = maxCycle > cycle ? maxCycle : cycle;
    }

    return maxCycle;
}
