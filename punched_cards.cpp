#include <stdio.h>
using namespace std;


void printTop(int b) {
    printf("..");
    for (int i = 0; i < b - 1; i++) {
        printf("+-");
    }
    printf("+\n");
}
void printMid(int b) {
    for (int i = 0; i < b; i++) {
        printf(".|");
    }
    printf("\n");
}
void printBot(int b) {
    for (int i = 0; i < b; i++) {
        printf("+-");
    }
    printf("+\n");
}

int main() {
    int num;
    int row[86];
    int col[86];

    scanf("%d", &num);
    for (int i = 0; i < num; i++) {
        scanf("%d %d", &row[i], &col[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("Case #%d:\n", i + 1);

        printTop(col[i]);
        printf(".");
        printMid(col[i]);
        for (int j = 0; j < row[i] - 1; j++) {
            printBot(col[i]);
            printf("|");
            printMid(col[i]);
        }
        printBot(col[i]);
    }
    return 0;
}