// |demo_C.cpp|: demonstrate |C()|

#include <iostream>

using namespace std;

#define     alen(a)     (sizeof (a) / sizeof *(a))

int * buffered_array(const int [], int, int);

void display(const int *, size_t);

int
main()
{
    const int phone_digits[] = { 3, 3, 1, 2, 9, 1, 5 };
    int * phone_digits_ = buffered_array(phone_digits, alen(phone_digits), 5);
    display(phone_digits_, alen(phone_digits) + 5);
    cout.put('\n');
    delete [] phone_digits_;
    cout << "done\n";
}

void
display(const int * ia_p, size_t len)
{
    char sep_ch = '{';
    for ( const int * ia_end = ia_p + len ;
            ia_p < ia_end ;
            ++ia_p, sep_ch = ','
            )
        cout << sep_ch << ' ' << *ia_p;
    cout << " }";
}




int * buffered_array(const int array[], int len, int incr) {
	int * p1;
	p1 = new int [len + incr];
	for (int i = 0; i < len; ++i) {
		p1[i] = array[i];
	}
	return p1;
}

