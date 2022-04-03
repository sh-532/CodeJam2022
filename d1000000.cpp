#include <stdio.h>
using namespace std;

void qsort(int* arr, int start, int end) {
	if (start >= end) {
		return;
	}

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int temp;

	while (i <= j) {
		while (i <= end && arr[i] <= arr[pivot]) {
			++i;
		}
		while (j > start && arr[j] >= arr[pivot]) {
			--j;
		}
		if (i >= j) break;

		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	temp = arr[j];
	arr[j] = arr[pivot];
	arr[pivot] = temp;

	qsort(arr, start, j - 1);
	qsort(arr, j + 1, end);

}

int main(void) {
	int n, dice, temp, cnt, j;
	int diceSides[1000005];
	int ans[100005];

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &dice);
		for (int j = 0; j < dice; j++) {
			scanf("%d", &diceSides[j]);
		}

		qsort(diceSides, 0, dice - 1);

		cnt = 1;
		j = 0;
		for (int j = 0; j < dice; j++) {
			if (cnt <= diceSides[j]) cnt++;
		}
		ans[i] = cnt - 1;
	}
	for (int i = 0; i < n; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}