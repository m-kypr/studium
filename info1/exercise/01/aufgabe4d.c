#include <stdio.h>

void penis(char c[]) {
	int s = sizeof(&c) + 1;
	char b[s];
	for (int i = 0; i < s; i++) {
		/* Lookup ASCII Table if this is not clear */
		if (c[i] > 47 && c[i] < 58) {
			b[i] = (c[i] << 1) + 1;
		} else {
			b[i] = c[i];
		}
	}
	printf("%s\n%s\n", c, b);
}

int main() {
	penis("trump2020");
	return 0;
}
