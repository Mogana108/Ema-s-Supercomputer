#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int N;
int M;

char grid[16][16];


void markPlus(int i, int j, int l, char c)
{
    int k;
    grid[i][j] = c;
    for (k = 1; k <= l; ++k) {
        grid[i+k][j] = c;
        grid[i-k][j] = c;
        grid[i][j+k] = c;
        grid[i][j-k] = c;
    }
}


int checkPlus(int i, int j, int l)
{
    int res = 1;
    int k;
    do {
        if (grid[i][j] != 'G') {
            res = 0;
            break;
        }

        for (k = 1; k <= l; ++k) {
            if (grid[i+k][j] != 'G') {
                res = 0;
                break;
            }
            if (grid[i-k][j] != 'G') {
                res = 0;
                break;
            }
            if (grid[i][j+k] != 'G') {
                res = 0;
                break;
            }
            if (grid[i][j-k] != 'G') {
                res = 0;
                break;
            }
        }
    } while (0);
    return res;
}


int findPlus(int l)
{
    int i;
    int j;

    for (i = l; i < N - l; ++i) {
        for (j = l; j < M - l; ++j) {
            if (checkPlus(i, j, l)) {
                return 1;
            }
        }
    }
    return 0;
}


int main()
{
    int i;
    int j;
    int k;
    int m;
    int res = 0;
    int p1;
    int p2;
    int biggest;

    scanf("%d %d", &N, &M);
    for (i = 0; i < N; ++i) {
        scanf("%s", grid[i]);
    }

    biggest = N;
    if (M < biggest) {
        biggest = M;
    }
    biggest /= 2;

    for (i = 0; i <= biggest; ++i) {
        p1 = 1 + 4 * i;
        for (j = i; j < N-i; ++j) {
            for (k = i; k < M-i; ++k) {
                if (checkPlus(j, k, i)) {
                    markPlus(j, k, i, 'B');
                    for (m = 0; m <= biggest; ++m) {
                        p2 = 1 + 4 * m;
                        if (findPlus(m)) {
                            if (p1 * p2 > res) {
                                res = p1 * p2;
                            }
                        }
                    }
                    markPlus(j, k, i, 'G');
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
