#include <iostream>
using namespace std;
#include <vector>

//bool isLeap(int year) {
//    if (year % 4 != 0) {
//        return false;
//    }
//    else if (year % 100 != 0) {
//        return true;
//    }
//    else if (year % 400 != 0) {
//        return false;
//    }
//    else {
//        return true;
//    }
//}
//
//int main() {
//    for (int yr = 1995; yr < 2017; yr++) {
//        cout << yr << " -> " << isLeap(yr) << endl;
//    }
//    return 0;
//}



bool isLeap(int year) {
    if (year % 4 != 0) {
        return false;
    }
    else if (year % 100 != 0) {
        return true;
    }
    else if (year % 400 != 0) {
        return false;
    }
    else {
        return true;
    }
}

int monthLength(int year, int month) {
    vector<int> daysInMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 }; 
    if (month == 2 && isLeap(year)) { 
        return 29;
    }
    return daysInMonth[month - 1]; 
}

int main(void) {
    for (int yr = 2000; yr < 2002; yr++) {
        for (int mo = 1; mo <= 12; mo++)
            cout << monthLength(yr, mo) << " ";
        cout << endl;
    }
    return 0;
}

