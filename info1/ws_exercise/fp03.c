#include <stdio.h>
#include <stdlib.h>


int rgb(int n) {
        for (int i = 0; i < n; i++) {

                int hex = rand() % 16777216;
                
                int r = ((hex >> 16) & 0xFF) / 255.0;
                int g = ((hex >> 8) & 0xFF) / 255.0;
                int b = ((hex) & 0xFF) / 255.0;
                
                printf("%i ", hex);
        }
        printf("\n");
}


long double power3(int n) {
        long double r = 3;
        for (int i = 0; i < n; i++) {
                r *= r;
        }
        return r;
}

int main() {
        rgb(50);
        return 0;
}
