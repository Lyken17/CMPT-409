#include <iostream>
#include <algorithm>

#define MAX_ARRAY 800000
#define MAX_SIZE 2000000000 + 1000
using namespace std;

long long g[MAX_ARRAY];


int main(int argc, char const *argv[]) {
    g[1] = 1;
    g[2] = 3;


    // g(n)=max{ m | f(m)=n}
    int pos = 2;
    for (int i = 3;i < MAX_ARRAY; ++i) {
        while(g[pos] < i) ++pos;
        g[i] = g[i-1] + pos;
    }


    int n;


    while(cin >> n) {
        if (n == 0) break;
        cout << lower_bound(g + 1, g + MAX_ARRAY, n) - g << endl;
        // f(n) = min{ k | g[k]>=n}
    }

    return 0;
}
