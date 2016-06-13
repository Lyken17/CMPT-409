#include <iostream>
#include <algorithm>

using namespace std;

inline int smallest(int x, int y, int z){
    return std::min(std::min(x, y), z);
}

int main(int argc, char const *argv[]) {
    int n;
    while (cin >> n) {
        ++n;
        long long  arr[n];

        for (size_t i = 0; i < n; i++)
            arr[i] = 0;
        arr[0] = 1;

        for (size_t i = 1; i < n; i++)
            for (size_t j = 1; j <= smallest(3, n-1, i); j++)
                arr[i] += j == 1 ? 2 * arr[i-j] : arr[i-j];

        cout << arr[n-1] << endl;

    }
    return 0;
}
