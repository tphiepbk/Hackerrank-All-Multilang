#include <iostream>
#include <vector>

using namespace std;

int fairRations(vector<int> B) {
    int numOfBreads = 0;
    for (int i = 0 ; i < B.size() ; i++) {
        if (i == B.size() - 1) {
            if (B[i] % 2 != 0) return -1;
        } 
        if (B[i] % 2 != 0) {
            B[i] += 1;
            B[i+1] += 1;
            i--;
            numOfBreads += 2;
        }
    }
    return numOfBreads;
}

int main() {
    vector<int> arr = {1,2};
    cout << fairRations(arr);
}