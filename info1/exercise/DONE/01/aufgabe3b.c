#include <stdio.h>

int main() {
	printf("dec | oct | hex\n");
	for(int i = 0; i < 1001; i++) {
		printf("%d | %o | %x\n", i, i, i);
	}

	return 0;

}
