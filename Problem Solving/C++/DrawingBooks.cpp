#include <bits/stdc++.h>
#include <cmath>

using namespace std;

/*
 * Complete the pageCount function below.
 */
int pageCount(int n, int p) {
    /*
     * Write your code here.
     */
    if (n == p) return 0;
    if (p == 1) return 0;
    if (n % 2 == 0 && n - p == 1) return 1;
    if (n % 2 != 0 && n - p == 1) return 0; 
    int fromBegin = 0;
    int fromEnd = 0;
    if (n % 2 == 0) {
        if (p % 2 == 0) fromEnd = (n - p) / 2;
        else fromEnd = (n - p) / 2;
    } 
    else if (n % 2 != 0) {
        if (p % 2 != 0) fromEnd = (n - p) / 2;
        else fromEnd = trunc((n - p) / 2);     
    }
    if (p % 2 == 0) fromBegin = trunc((p - 1) / 2) + 1;
    else fromBegin = (p - 1) / 2;
    if (fromEnd <= fromBegin) return fromEnd;
    else return fromBegin;;
}

int main() {
    cout << pageCount(6,2) << "\n";
}