#include <bits/stdc++.h>
#include <string>

using namespace std;

// Complete the dayOfProgrammer function below.
string dayOfProgrammer(int year) {
    int febDays = 0;
    int totalNumOfDays = 0;
    int resDay = 0;
    string res = "";
    if (year >= 1700 && year <= 1917) { // Julian Calendar
        if (year % 4 == 0) febDays = 29;
        else febDays = 28;
    }
    else if (year == 1918) {
        febDays = 15;
    }
    else { // Gregorian Calendar
        if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) febDays = 29;
        else febDays = 28;
    }
    totalNumOfDays = 31 + febDays + 31 + 30 + 31 + 30 + 31 + 31;
    resDay = 256 - totalNumOfDays;
    if (resDay < 10) res = res + "0" + to_string(resDay);
    else res +=  to_string(resDay);
    res = res + ".09." + to_string(year);
    return res;
}

int main() {
    cout << dayOfProgrammer(2015) << "\n";
}