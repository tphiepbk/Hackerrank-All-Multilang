#include <bits/stdc++.h>

using namespace std;

// Complete the divisibleSumPairs function below.
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    for (int i = 0 ; i < n-1 ; i++) {
        for (int j = i+1 ; j < n ; j++) {
            if ((ar[i] + ar[j]) % k == 0) count++;
        }
    }
    return count;
}

int main() {
    vector<int> ar = {1,3,2,6,1,2};
    cout << divisibleSumPairs(6,3,ar) << "\n";
}
