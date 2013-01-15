#include <iostream>
#include <cmath>
using namespace std;

const float gr = 1.61803398874989484820458683f;
const float sqr5 = 2.2360679774997896964091f;

//O(1)
int F (int i) {
    return floor((pow(gr,i+1)-pow(1-gr,i+1))/sqr5);
}

//O(sqrt(i))
int isqrt (int i) {
    int n = 1;
    while (n*n <= i ){
        n += 1;
    }
    return n - 1;
}

int main () {
    int i;
    while (true) {
        cout << "Enter i: ";
        cin >> i;
        if ( i > -1 ) {
            cout << "F(" << i << ") = " << F(i) << "\n";
            cout << "isqrt(" << i << ") = " << isqrt(i) << "\n";
            cout << "sqrt(" << i << ") = " << sqrt(i) << "\n";
        }
        else {
            cout << "Can't handle negative input, so quitting.\n";
            return 0;
        }
    }
}
    
