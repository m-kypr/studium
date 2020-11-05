#include <stdio.h>

int compare_arrays(int v[], int w[], int size_v, int size_w) {
	int e = 0;
	for (int i = 0; i < size_v && i < size_w; i++) {
		if (v[i]!=w[i]) e = 1;
	}
	return e;
}

int main() {
	int a[] = { 1, 4, 6, 2, 7, 5, 8 };
	int b[] = { 1, 4, 6, 2 };
	int c = compare_arrays(a, b, 7, 4);
	printf("%d\n", c);
	return 0;
}
