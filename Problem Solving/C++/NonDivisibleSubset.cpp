#include <bits/stdc++.h>

using namespace std;


int nonDivisibleSubset(int k, vector<int> s) {
    vector<int> tempRes1;
    vector<int> tempRes2;
    for (int i = 0 ; i < s.size() - 1 ; i++) {
        for (int j = i + 1 ; j < s.size() ; j++) {
            if ((s[i] + s[j]) % k != 0) {
                tempRes1.push_back(s[i]);
                tempRes1.push_back(s[j]);
            }
        }
    }

    int countForNull = 0;
    for (int i = 0 ; i < tempRes1.size()-1 ; i++) {
        for (int j = i + 1 ; j < tempRes1.size() ; j++) {
            if (tempRes1[j] == -1) continue;
            if (tempRes1[j] == tempRes1[i]) {
                tempRes1[j] = -1;
            }
        } 
    }

    int res = 0;
    while (!tempRes1.empty()) {
        if (tempRes1.back() != -1) res++;  
        tempRes1.pop_back();
    }

    return res;
}

int main() {
    vector<int> arr = {278, 576, 496, 727, 410, 124, 338, 149, 209, 702, 282, 718, 771, 575, 436};
    cout << nonDivisibleSubset(7, arr);
}
