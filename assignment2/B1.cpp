#include <iostream>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
using namespace std;

//We make sure that each time we place a random number into the list it is not a duplicate and we only use numbers in the desired range and so every permutation must be legal.
//The odds of any number being placed in any position is equally likely and so each permutation is equally likely.

//The worst case is an infinite loop. It is theoretically possible for random numbers to be produced that are always invalid.

//O(n^2)
int main (int argc, const char* argv[]) {
    for (int k = 0; k<10; k++){
        
        //each of these executed once
        srand(time(NULL));
        int n = atoi(argv[1]);
        int a [n];
        bool repeat;
        int i = 0;
        int r;

        //executed at the beginning once
        while (i < n) { //this loop is executed approximately n times
            repeat = false; //executed approximately n times
            r = (rand() % n) + 1; //executed approximately n times
            //assume that there is no repeat
            for (int j = 0; j<i; j++) { //inner loop is executed at most n times
                //either 1 or three statements executed at most n times
                if (r == a[j]) {
                    repeat = true;
                    break;
                }
            }
            //either 1 or three statements executed
            if (!repeat) {
                a[i] = r;
                i++;
            }
        }
    }
//T(n) is approximately 6 + 3n + n*(3n) + 3n which makes it Big-Oh(n^2)

}
