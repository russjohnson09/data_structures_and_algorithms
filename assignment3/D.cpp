/* |astr.cpp|: pointer-exercising code */

#include <iostream>
#include <string>
using namespace std;

void  astr(string*);

int
main()
{
    string s1("zero");
    string s2("infinity");
    astr(&s1);
    astr(&s2);
}

void
astr(string* str)
{
    cout << "invocation of |astr(\"" <<  *str << "\")| successful\n";
}
