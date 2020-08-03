#include <iostream>
#include <cmath>

using namespace std;

int saveThePrisoner(int n, int m, int s) {
    int numberOfCandyForEach = 0; // Số kẹo chuẩn cho mỗi người
    if (m % n == 0) numberOfCandyForEach =  m / n;
    else numberOfCandyForEach = trunc(m/n)+1;
    int temp = numberOfCandyForEach * n; // Tổng số kẹo chuẩn cho mỗi người
    int temp2 = temp - m; // Số người ko có kẹo ở lượt phát cuối cùng nếu bắt đầu ở 1
    int lastPosOfCandy = n - temp2; // Người cuối cùng có kẹo nếu bắt đầu ở 1
    if (s == 1) return lastPosOfCandy;
    else {
        int temp3 = lastPosOfCandy + (s-1);
        while (temp3 > n) temp3 = temp3 - n;
        return temp3;
    }
}

int main() {
    int numOfTestCase = 0;
    cin >> numOfTestCase;
    int n,m,s;
    while (numOfTestCase--) {
        cin >> n >> m >> s;
        cout << saveThePrisoner(n,m,s) << "\n";
    }
}