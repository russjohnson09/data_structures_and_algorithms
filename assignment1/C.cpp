#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main () {
    srand(time(NULL));
    int i;
    int j;
    cout << "Enter i: ";
    cin >> i;
    cout << "Enter j: ";
    cin >> j;
    cout << "randInt(i,j): " << rand() % ((j-i)+1) + i << "\n";
}
