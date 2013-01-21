#include <cctype>
#include <set>
#include<iostream>

std::multiset<char> make_key(const char* chars)
{
    std::multiset<char> key ;
	while (*chars != '\0'){
		key.insert(*chars);
		++chars;
	}
    return key ;
}

int main(int argc, const char* argv[]) {
	bool b = make_key(argv[1]) == make_key(argv[2]);

	std::cout << b;

}
