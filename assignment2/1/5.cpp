#include <iostream>
#include <cstdlib>
using namespace std;

//O(n^5)
int main(int argc, const char* argv[])
{
    int n = atoi(argv[1]);
    int sum = 0;
    for ( int i = 0 ;  i < n ;  i++ ) {
        for ( int j = 0 ;  j < i * i ;  j++ ) {
            for ( int k = 0 ;  k < j ;  k++ ) {
                sum++;
            }
        }
    }
    return 0;
    
}
