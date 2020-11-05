#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randrange(int min, int max)
{
	return rand() % (max+ 1 - min) + min;
}



int main() 
{
	int i;
	int j;
	int r;
	srand(time(NULL));
	r = randrange(6, 14);
	printf("r=%i\n", r);

	for(i = r; i > 0; i--) {
		for (j = 0; j < i; j++) 
		{
			printf("0");
		}
		printf("\n");
	}
	return 0;
}
