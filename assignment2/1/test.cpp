#include <stdio.h>
#include <cstdlib>
int main( int argc, const char* argv[] )
{
	int x;
	int y;
	
	// ensure the correct number of parameters are used.
	if ( argc == 3 ) 
	{
		x = atoi( argv[1] );
		y = atoi( argv[2] );
		
		printf( "%d + %d = %d\n", x, y, x + y );
		
		// Will print something like: 3 + 2 = 5
	}

}
