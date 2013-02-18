#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void recurse(int * ap, int n);

int
main()
{
    srand(time(NULL));
    int x = -1;
    int a[] = { rand(), rand(), rand(), rand(), rand() };
    int y = -1;
    x = y;
    y = x;
    for ( int i(0); i < 5 ; i++ )
        cout << a[i] << ' ';
    cout << '\n';
    recurse(a, 5);
}

void
recurse(int * ap, int n)
{
    if ( n > 0 )
        recurse(ap + 1, n - 1);
    cout << "recurse( {" << *ap << ",...}, " << n << "}\n";
}
