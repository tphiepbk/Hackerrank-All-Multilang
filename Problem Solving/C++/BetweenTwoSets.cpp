#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getTotalX(vector<int> a, vector<int> b) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int maxRange = 0, minRange = 0;
    if (a.front() < b.front()) minRange = a.front();
    else minRange = b.front();
    if (a.back() >= b.back()) maxRange = a.back();
    else maxRange = b.back();

    int count = 0;
    for (int current = minRange ; current <= maxRange ; current++) {
        int checkA = 0;
        int checkB = 0;
        for (int i = 0 ; i < a.size() ; i++) {
            if (current % a[i] != 0) {
                checkA++;
                break;
            }
        }
        for (int i = 0 ; i < b.size() ; i++) {
            if (b[i] % current != 0) {
                checkB++;
                break;
            }
        }
        if (checkA == 0 && checkB == 0) count++;
    }
    return count;
}

int main() {
    vector<int> a = {2, 4};
    vector<int> b  = {16, 32, 96};
    cout << getTotalX(a,b);    
}