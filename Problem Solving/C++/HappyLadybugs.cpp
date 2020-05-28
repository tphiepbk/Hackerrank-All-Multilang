#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    map<char, int> bugs;
    map<char, int>::iterator it;
    int countForEmpty = 0;
    int countForExist = 0;
    for (int i = 0 ; i < b.length() ; i++) {
        if (b[i] == '_') countForEmpty++;
        else {
            if (bugs.empty()) bugs.insert(pair<int, int>(b[i], 1));
            else {
                countForExist = 0;
                for (auto it = bugs.begin() ; it != bugs.end() ; ++it) {
                    if (it->first == b[i]) {
                        (it->second)++;
                        countForExist++;
                    }
                }
                if (countForExist == 0) bugs.insert(pair<int, int>(b[i], 1));
            }
        }
    }

    int countNotHappy = 0;
    for (int i = 0 ; i < b.length() ; i++) {
        if (b[i] == '_') continue;
        if (i == 0) {
            if (b[i+1] != b[i] && b[i+1] != '_') countNotHappy++;
        }
        else if (i == b.length() - 1) {
            if (b[i-1] != b[i] && b[i-1] != '_') countNotHappy++;
        }
        else {
            if ( (b[i-1] == '_' && b[i+1] != b[i]) || (b[i+1] == '_' && b[i-1] != b[i]) || (b[i+1] != b[i] && b[i-1] != b[i] && b[i-1] != '_' && b[i+1] != '_') ) countNotHappy++;
        }

    }
    int alone = 0;
    for (auto it = bugs.begin() ; it != bugs.end() ; ++it) {
        if (it->second == 1) alone++;
    } 
    if (countForEmpty > 0 && alone == 0) return "YES";
    else if (countForEmpty == 0 && alone == 0 && countNotHappy == 0) return "YES";
    else return "NO";
}


int main() {
    string b = "X_Y__X";
    cout << happyLadybugs(b);
}