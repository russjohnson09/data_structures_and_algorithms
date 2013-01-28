#include "dvd.h"
#include <iostream>
#include <string>
using namespace std;

DVD::DVD(const string t, int m, double p) : title(t), minutes(m), price(p) {
}

void DVD::output() const {
	cout << "Title: " << title << '\n' << "Minutes: " << minutes << '\n' << "Price: " << price << '\n';
}

void DVD::changeprice(double p_new) {
	price = p_new;
}

int main() {
	const DVD diehard("Die Hard", 130, 9.99);
	DVD stein("Stein's Gate", 120, 10.11);
	DVD bun("Bunraku", 121, 3.56);

	diehard.output();
	stein.output();
	bun.output();

	stein.changeprice(1.11);
	bun.changeprice(0);

	diehard.output();
	stein.output();
	bun.output();
	
	cout << diehard.get_title() << '\n';
	cout << stein.get_minutes() << '\n';
	cout << bun.get_price() << '\n';
}
