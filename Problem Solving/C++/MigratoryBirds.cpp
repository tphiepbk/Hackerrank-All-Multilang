#include <bits/stdc++.h>
#include <map>

using namespace std;

// Complete the migratoryBirds function below.
int migratoryBirds(vector<int> arr) {
    map<int, int> birds;
    map<int, int>::iterator it;
    int countForExistence = 0;
    for (int i = 0 ; i < arr.size() ; i++) {
        if (birds.empty()) birds.insert(pair<int, int>(arr[i], 1));
        else {
            countForExistence = 0;
            for (auto it = birds.begin() ; it != birds.end() ;  ++it) {
                if (it->first == arr[i]) {
                    it->second += 1;
                    countForExistence++;
                }
            }
            if (countForExistence == 0) birds.insert(pair<int, int>(arr[i], 1));
        }
    }
    int resID = 0;
    int maxNum = 0;
    for (auto it = birds.begin() ; it != birds.end() ; ++it) {
        if (it->second >= maxNum) {
            maxNum = it->second;
            resID = it->first;
        }
    }
    for (auto it = birds.begin() ; it != birds.end() ; ++it) {
        if (it->second == maxNum && it->first <= resID) {
            resID = it->first;
        }
    }
    return resID;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
    cout << migratoryBirds(arr) << "\n";
}