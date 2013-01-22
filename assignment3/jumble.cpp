#include <cstdlib>
#include <cctype>
#include <set>
#include<iostream>
#include<cstring>

using namespace std;

multiset<char> make_set(const char* chars)
{
    multiset<char> key ;
	while (*chars != '\0'){
		key.insert(*chars);
		++chars;
	}
    return key ;
}


char* unscramble(const char* str1)
{
	char* result = "";
    string line;
    while(getline(cin, line))
    {
		char* str2 = new char [line.length()+1];
		strcpy (str2, line.c_str());
        if (make_set(str1) == make_set(str2)) {
			result = str2;
		}
    }
	return result;
}

int main(int argc, const char* argv[]) {

	cout << unscramble(argv[1]) << "\n";
		
}
