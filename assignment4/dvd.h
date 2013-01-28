#ifndef DVD_H
#define DVD_H

#include <string>
using namespace std;


// class definition
class DVD {
    const string title;
    const int minutes;
    double price;

  public:
    DVD(const string t, int m, double p);
    void output() const;
    void changeprice(double p_new);
	string get_title() const {return title;}
	const int get_minutes() const {return minutes;}
	const double get_price() const {return price;}
  };

#endif  /* DVD_H */
