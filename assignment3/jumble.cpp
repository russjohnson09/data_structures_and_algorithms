#include<iostream>

using namespace std;

void f()
{
    string line;
    while(getline(cin, line))  //input from the file in.txt
    {
        cout << line << "\n";   //output to the file out.txt
    }
}

int main(int argc, const char* argv[]) {

	f();
		
}
