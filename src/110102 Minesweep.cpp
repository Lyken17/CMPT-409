#include <iostream>

using namespace std;



int m, n;

bool inBoard(int x, int y) {
    if (x < 0 || y < 0 || x >= m || y >= n)
        return false;
    else
        return true;
}


int main() {
    char mine[101][101];
    int num[101][101];
    int nFields = 0;

    while (scanf("%u %u", &m, &n) && m && n) {
        for (int i = 0; i < m; ++i) {
            scanf("%s", mine[i]);
        }

        // process
        int x,y;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {

                int nMines = 0;

                if (mine[i][j] == '.') {
                    for (int k = -1; k <= 1; ++k) {
                        for (int l = -1; l <= 1; ++l) {
                            x = i + k;
                            y = j + l;
                            if (inBoard(x, y) && mine[x][y] == '*') ++nMines;
                        }
                    }
                    mine[i][j] = '0' + nMines;
                }

            }
        }

        // output
        if (nFields > 0)
            printf("\nField #%d:\n", ++nFields);
        else
            printf("Field #%d:\n", ++nFields);

        for (int i = 0; i < m; ++i) {
            printf("%s\n", mine[i]);
        }

    }
}
