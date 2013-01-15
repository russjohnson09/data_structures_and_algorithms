#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

//This algorithm follows the same logic as B1 and for this reason it also produces only legal permutations with equal likelyhood.

//The worst case is an infinite loop. It is theoretically possible for random numbers to be produced that are always invalid.

//O(n)
int main (int argc, const char* argv[]) {
    for (int k = 0; k<10; k++){

        //4 statements
        srand(time(NULL));
        int n = atoi(argv[1]);
        int a [n];
        bool used [n];

        //3n + 2 total statements
        for (int j = 0; j < n; j++) 
            used[j] = false;

        //2 statements
        int i = 0;
        int r;
        
        //approximately n loops and 6 statements per loop
        while (i < n) {
            r = (rand() % n) + 1;
            if (!used[r-1]) {
                used[r-1] = true;
                a[i] = r;
                i++;
            }
        }
    }
}
//T(n) is approximately 4 + (3n + 2) + 6n  which makes it Big-Oh(n)
