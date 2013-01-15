#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;
//Each swap results in a legal permutation and this algorithm only uses swaps to modify the list and so each permutation from the algorithm must be legal.
//A swap between two positions is equally likely and so each resulting permutation is equally likely.
//The odds of getting {1,2,3} is (1/3)^3 and there are nine possible permutations.

//The worst case is O(n).

//O(n)
int main (int argc, const char* argv[]) {
    for (int i = 0; i<10; i++){
        //4 
        srand(time(NULL));
        int n = atoi(argv[1]);
        int a [n];
        //3n + 2 statements
        for (int i = 0; i<n; i++)
            a[i] = i+1;

        //7n + 2 statements
        for (int i = 0; i<n; i++) {
            int r = (rand() % n);
            int temp1 = a[i];
            int temp2 = a[r];
            a[i] = temp2;
            a[r] = temp1;
        }
    }
}
//T(n) is approximately 4 + (3n + 2) + (7n + 2)  which makes it Big-Oh(n)
