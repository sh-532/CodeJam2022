#include <stdio.h>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

int printer[310][4];

int getMin(int start, int col) {
    int temp;
    temp = MIN(printer[start][col], printer[start + 1][col]);
    temp = MIN(temp, printer[start + 2][col]);

    return temp;
}


int main() {
    int num, total;
    int possible[105][5];
    scanf("%d", &num);

    for (int i = 0; i < num * 3; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &printer[i][j]);
        }
        possible[i][4] = 0;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 4; j++) {
            possible[i][j] = getMin(i * 3, j);
            possible[i][4] += possible[i][j];
        }
    }

    for (int i = 0; i < num; i++) {
        total = 0;
        printf("Case #%d: ", i + 1);
        if (possible[i][4] < 1000000) printf("IMPOSSIBLE");
        else {
            for (int j = 0; j < 4; j++) {
                if (total >= 1000000) printf("0 ");
                while (total < 1000000) {
                    int answer = MIN(1000000 - total, possible[i][j]);
                    printf("%d ", answer);
                    total += possible[i][j];
                    break;
                }
            }
        }
        printf("\n");
    }
    return 0;
}