#include <iostream>
#include <cstdlib>
using namespace std;

//O(n^4)
//Running Times
//n = 1 : s < 1
//n = 10 : s < 1
//n = 100 : s < 1
//n = 1000 : s > 15
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
