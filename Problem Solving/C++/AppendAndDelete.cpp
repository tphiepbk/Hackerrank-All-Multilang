#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int numOfMoves = 0;
    int deltaLen = abs((int)s.length() - (int)t.length());

    int minLen = 0;
    int maxLen = 0;
    if (s.length() < t.length()) {
        minLen = s.length();
        maxLen = t.length();
    }
    else {
        minLen = t.length();
        maxLen = s.length();
    }

    int commonLen = 0;
    for (int i = 0 ; i < minLen ; i++) {
        if (s[i] == t[i]) commonLen++;
        else break;
    }
    
    if (commonLen + deltaLen != maxLen) {
        numOfMoves = deltaLen + (maxLen - commonLen - deltaLen) * 2;
    }
    else numOfMoves = deltaLen;

    if (numOfMoves > k) return "No"; 
    if (numOfMoves == k) return "Yes";

    for (int i = 0 ; i < commonLen ; i++) {
        numOfMoves += 2;
        if (numOfMoves == k) return "Yes";
    } 

    if (numOfMoves > k) return "No";
    else return "Yes";
}

int main() {
    string s = "qwerasdf";
    string t = "qwerbsdf";
    cout << appendAndDelete(s,t,6);
}