#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
	srand(time(NULL));
	int a = rand()%1000;
	printf("%d\n", a);
	int n = a;
	for(int i = 1; i <= a; i++) {
		if(a%i==0) printf("%d\n", i);
	}
	return 0;
}
