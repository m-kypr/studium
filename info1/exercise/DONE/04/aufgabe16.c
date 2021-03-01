#include <stdio.h>
#include <stdlib.h>

#define INT_BIT sizeof(int)*8

void print_bits(int b[], int size)
{
        for (int i = size-1; i >= 0; i--)
        {
                printf("%i", b[i]);
        }
        printf("\n");
}

void init_bits(int b[], int size)
{
        for (int i = 0; i < size; i++)
        {
                b[i] = 0;
        }
}

int pow69(int n)
{
        int p;
        p = 1;
        for (int i = 0; i < n; i++)
        {
                p = p + p;
        }
        return p;
}

void get_bits(int b[], int n)
{
        for (int i = INT_BIT-1; i > -1; i--)
        {       
                int p;
                p = pow69(i);
                if (n - p > -1) 
                {
                        b[i] = 1;        
                        n = n - p;
                        if (n == 0) return;
                } 
        }
}

/*
Integer Overflow bei -2147483648-1 und 2147483647+1
*/
int get_int(int b[])
{
        int r;
        int flip;
        flip = 0;
        r = 0;
        for (int i = INT_BIT-1; i > -1; i--)
        {

                if (b[i] == 1 && i == INT_BIT-1)
                {
                        flip = 1;
                }
                if (flip == 1)
                {
                        /*
                        Kann man wahrscheinlich besser lösen...
                        */
                        if (b[i] == 1) b[i] = 0;
                        else if (b[i] == 0) b[i] = 1;
                }
        }
        for (int i = INT_BIT-1; i > -1; i--)
        {
                if (b[i] == 1)
                {
                        r += pow69(i);
                }
        }
        if (flip == 1)
        {
                return -r-1;
        }
        return r;
}
                        


int main(int argc, char *argv[])
{
        int a;
        int b[INT_BIT];
        printf("INT_BIT=%li\n", INT_BIT);
        init_bits(b, INT_BIT);
        if (argc > 1) {
                get_bits(b, atoi(argv[1]));
        } else {
                get_bits(b, 420); 
        }
        print_bits(b, INT_BIT);
        a = get_int(b);
        printf("a=%i\n", a);
        
        return 0;
}
