#include <stdio.h>

void manipulate_and_print(int v[], int size) {
	for(int i = 0; i < size; i++) {
		if (v[i] < 0) printf("%d\n", v[i]*2);
		else {
			if (v[i] % 2) {
				printf("%d\n", v[i]+1);
			} else {
				printf("-%d\n", v[i]);
			}
		}
	}

}

int main() {
	int a[] = { 1, 2, 3, 4 };
	manipulate_and_print(a, 4);
	return 0;
}
