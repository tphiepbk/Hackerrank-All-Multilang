#include <bits/stdc++.h>
#include <map>

using namespace std;

// Complete the equalizeArray function below.
int equalizeArray(vector<int> arr) {
    map<int, int> mArr;
    map<int, int>::iterator it;
    int countForExist = 0;
    for (int i = 0 ; i < arr.size() ; i++) {
        countForExist = 0;
        if (mArr.empty()) {
            mArr.insert(pair<int, int>(arr[i], 1));
            continue;
        }
        for (auto it = mArr.begin()++ ; it != mArr.end() ; ++it) {
            if (it->first == arr[i]) {
                countForExist++;
                (it->second)++; 
            }
        }
        if (countForExist == 0) mArr.insert(pair<int, int>(arr[i], 1));
    }
    int countMax = 0;
    for (auto it = mArr.begin() ; it != mArr.end() ; ++it) {
        if (it->second >= countMax) countMax = it->second;
    }
    return (arr.size() - countMax);
}

int main() {
    vector<int> arr = {3,3,2,1,3};
    cout << equalizeArray(arr);
}