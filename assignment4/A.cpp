//A.cpp
#include "dvd.cpp"

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
