#include <string>
#include<iostream>

using namespace std;

int main() {

	string str1 = "hello";
	string::iterator it;

	for (string::iterator it = str1.begin(); it < str1.end(); ++it) {
		cout << *it;
	}

}
