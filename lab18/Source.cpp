#include <iostream>
using namespace std;
#include <vector>
#include <ctime>
#pragma warning(disable : 4996)

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
//
//int main(void) {
//    for (int yr = 2000; yr < 2002; yr++) {
//        for (int mo = 1; mo <= 12; mo++)
//            cout << monthLength(yr, mo) << " ";
//        cout << endl;
//    }
//    return 0;
//}





struct Date {
    int year;
    int month;
    int day;
};

Date today(void) {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date d = { tl.tm_year + 1900, tl.tm_mon + 1, tl.tm_mday };
    return d;
}
int daysBetween(Date d1, Date d2) {
    int days = 0;
    for (int y = d1.year; y < d2.year; y++) {
        days += isLeap(y) ? 366 : 365;
    }
    for (int m = 1; m < d1.month; m++) {
        days -= monthLength(d1.year, m);
    }
    for (int m = 1; m < d2.month; m++) {
        days += monthLength(d2.year, m);
    }
    days += d2.day - d1.day;
    return days;
}

int main(void) {
    Date birthDate = { 2004, 5, 28 };
    Date currentDate = today();
    int days = daysBetween(birthDate, currentDate);
    cout << "Days since my birthday: " << days << std::endl;
    return 0;
}
