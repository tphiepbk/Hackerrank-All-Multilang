#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s,long n) {
    int countA = 0;
    vector<int> posA;
    for (int i = 0 ; i < s.length() ; i++) {
        if (s[i] == 'a') {
            countA++;
            posA.push_back(i+1);
        }
    }

    long totalA = (truncl(n / (long)s.length()) + 1) * countA;
    long totalWord = truncl(n / (long)s.length()) + 1;
    int tempPos;
    while (!posA.empty()) {
        tempPos = posA.back();
        posA.pop_back();
        if ((long)tempPos + (totalWord - 1)*(long)s.length() > n) totalA--;
    }
    return totalA;
}

int main() {
    string s = "aba";
    cout << repeatedString(s, 10);
}