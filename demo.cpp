#include "circular_list.h"
#include <iostream>

using namespace myproject;
using namespace std;

int main() {
    try {
        CircularList list;

        list += 10;
        list += 20;
        list += 30;

        cout << "After adding 10, 20, 30: ";
        list.print();

        list -= 20;
        cout << "After removing 20: ";
        list.print();

        list.update(10, 99);
        cout << "After changing 10 to 99: ";
        list.print();

        cout << "Element index 1: " << list[1] << endl;

        cout << "Is there 99? " << (list.contains(99) ? "Yes" : "No") << endl;

        !list;
        cout << "After cleaning: ";
        list.print();

        list += 42;
        list += 42;
    } catch (const MyProjectException& e) {
        cerr << "Error (MyProjectException): " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
    } catch (...) {
        cerr << "Unexpected error (...)!" << endl;
    }

    return 0;
}
