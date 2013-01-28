//driver.cpp
#include "LinkedList.cpp"

int main(void){
    LinkedList num;

    cout << "Number of items in the list: " << num.getNumberOfItems()
     << '\n' << num << '\n';

    num.insert(7);
    cout << "Number of items in the list: " << num.getNumberOfItems()
     << '\n' << num << '\n';

    num.insert(2);
    cout << "Number of items in the list: " << num.getNumberOfItems()
     << '\n' << num << '\n';

    num.insert(5);
    cout << "Number of items in the list: " << num.getNumberOfItems()
     << '\n' << num << '\n';

    if (!num.remove(8))
        cout << "8 could not be removed.\n";

    if (num.remove(2))
        cout << "2 was successfully removed.\n";

    cout <<"Number of items in the list: " << num.getNumberOfItems()
     << "\n" << num << '\n';

    if (num.remove(7))
        cout << "7 was successfully removed.\n";

    cout <<"Number of items in the list: " << num.getNumberOfItems()
     << "\n" << num << '\n';

    if (num.remove(5))
        cout << "5 was successfully removed.\n";

    cout <<"Number of items in the list: " << num.getNumberOfItems()
     << "\n" << num << '\n';

    if (!num.remove(8))
        cout << "8 could not be removed.\n";

    cout <<"Number of items in the list: " << num.getNumberOfItems()
     << "\n" << num << '\n';
}
