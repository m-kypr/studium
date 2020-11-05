#include <stdio.h>

void print_letters(char w[], int size) {
	for (int i = 0; i < size; i++) {
		if (i == size - 1) printf("%c\n", w[i]);
		else printf("%c, ", w[i]);	
	}
}

int main()
{
	print_letters("TEST", 2);
	return 0;
}
