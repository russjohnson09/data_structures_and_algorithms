#include <iostream>
#include <cstdlib>
using namespace std;

#define     alen(a)     (sizeof (a) / sizeof *(a))

void push(double);
double pop();
const int MAXVAL = 100;
int sp = 0;
double val [MAXVAL];

int main (int argc, const char* argv[]) {

	double op2;

	for (int i=1; i < argc; ++i) {
		char ch = argv[i][0];
		if ( ch == '-' && alen(argv[i]) > 1 )
			ch = argv[i][1];
		switch (ch) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				push(atof(argv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else
                        cerr << "error: zero divisor\n";
                    break;
			default:
					cerr << "error: unknown command " << argv[i];
					break;
			}
	}
	cout << "\t" << pop();
}

void push(double f) {
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		cerr << "error: stack full, can't push " << f;
}

double pop() {
	if (sp > 0)
		return val[--sp];
	else {
		cerr << "error: stack empty";
		return 0.0;
	}
}
