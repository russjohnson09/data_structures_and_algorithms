#include<iostream>

using namespace std;

int main(int argc, const char* argv[]) {

	const char* str;

	for (int i = 1; i < argc; i++) {
		str = argv[i];
		while (*str != '\0') {
			cout << *str;
			str++;
		}
		cout << '\n';
	}
		
}
