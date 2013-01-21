#include<iostream>

using namespace std;

int main(int argc, const char* argv[]) {

	const char * str1 = argv[1];
	const char * str2 = argv[2];

	while (*str1 != '\0' ) {
		cout << *str1;
		str1++;
	}
}
