#include "dvd.h"
#include <iostream>
#include <string>
using namespace std;

DVD::DVD(const string &t, int m, double p) : title(t), minutes(m), price(p) {
}

void DVD::output() const {
	cout << "Title: " << title << '\n' << "Minutes: " << minutes << '\n' << "Price: " << price << '\n';
}

void DVD::changeprice(double p_new) {
	price = p_new;
}
