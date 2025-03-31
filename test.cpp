#include "circular_list.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace myproject;
using namespace std;

void log_result(ofstream &logfile, const string &test_name, bool passed) {
    cout << test_name << " " << (passed ? "PASSED" : "FAILED") << endl;
    logfile << test_name << " " << (passed ? "PASSED" : "FAILED") << endl;
}

void testAddAndSize(ofstream &logfile) {
    CircularList list;
    list += 5;
    list += 10;
    bool passed = (list.size() == 2);
    log_result(logfile, "testAddAndSize", passed);
}

void testRemove(ofstream &logfile) {
    CircularList list;
    list += 5;
    list += 10;
    list -= 5;
    bool passed = (list.size() == 1);
    log_result(logfile, "testRemove", passed);
}

void testUpdate(ofstream &logfile) {
    CircularList list;
    list += 5;
    list.update(5, 15);
    bool passed = list.contains(15);
    log_result(logfile, "testUpdate", passed);
}

void testValidOperations(ofstream &logfile) {
    CircularList list;
    list += 1;
    list += 2;
    bool passed = (list.size() == 2);
    log_result(logfile, "testValidOperations", passed);
}

int main() {
    ofstream logfile("testlog.txt");

    if (!logfile) {
        cerr << "Error opening testlog.txt for writing" << endl;
        return 1;
    }

    testAddAndSize(logfile);
    testRemove(logfile);
    testUpdate(logfile);
    testValidOperations(logfile);

    logfile.close();
    return 0;
}
