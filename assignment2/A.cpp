#include <iostream>
#include <cstdlib>
#include <stdio.h>
using namespace std;


long fib ( int n ) {
    if ( n <= 1 )
        return 1;
    else 
        return fib(n-1) + fib(n-2);

}

int main(int argc, const char* argv[])
{
    int n = fib(atoi(argv[1]));

    printf ("%d\n", n);

    
}
