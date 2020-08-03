#include <bits/stdc++.h>

using namespace std;

// Complete the birthday function below.
int birthday(vector<int> s, int d, int m) {
    int count = 0;
    int tempSum = 0;
    for (int i = 0 ; i <= s.size() - m ; i++) {
        tempSum = 0;
        for (int j = i ; j < i+m  ; j++) {
            tempSum += s[j];
        }
        if (tempSum == d) count++;
    }
    return count;
}

int main() {
    vector<int> s = {1,2,1,3,2};
    cout << birthday(s,3,2) << "\n";
}