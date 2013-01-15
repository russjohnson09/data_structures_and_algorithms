#include <iostream>
#include <cstdlib>
using namespace std;

//O(n^4)
int main(int argc, const char* argv[])
{
    int n = atoi(argv[1]);
    int sum = 0;
    for ( int i = 1 ;  i < n ;  i++ ) {
        for ( int j = 1 ;  j < i * i ;  j++ ) {
            if ( j % i == 0 ) {
                for ( int k = 0 ;  k < j ;  k++ )
                    sum++;
            }
        }
    }
    return 0;
    
}
