#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkKaprekar(int num) {
    long squareNum = pow(num, 2);
    string strNum = to_string(num);
    int lenNum = strNum.length();
    string strSquareNum = to_string(squareNum);
    int lenSquareNum = strSquareNum.length();
    int startPos = lenSquareNum - lenNum;
    string right = strSquareNum.substr(lenSquareNum - lenNum, lenNum);
    string left = strSquareNum.substr(0, lenSquareNum - right.length());
    int leftNum = (left.length() == 0) ? 0 : stoi(left);
    int rightNum = (right.length() == 0) ? 0 : stoi(right);
    if (leftNum + rightNum == num) return true;
    return false; 
}

void kaprekarNumbers(int p, int q) {
    int check = 0;
    for (int i = p ; i <= q ; i++) {
        if (checkKaprekar(i)) {
            cout << i << " ";
            check++;
        }
    }
    if (check == 0) cout << "INVALID RANGE";
}

int main() {
    //cout << checkKaprekar(44);
    kaprekarNumbers(1,100);
}