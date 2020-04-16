#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    int countForPairs = 0;
    for (int i = 0 ; i < ar.size() - 1; i++) {
        if (ar[i] == -1) continue;
        for (int j = i+1 ; j < ar.size() ; j++) {
            if (ar[j] == -1) continue;
            if (ar[i] == ar[j]) {
                ar[j] = -1;
                countForPairs++;
                break;
            }
        }
    }
    return countForPairs;
}

int main() {
    vector<int> ar = {10 ,20, 20 ,10, 10, 30, 50, 10 ,20};
    cout << sockMerchant(ar.size(),ar) << "\n";
}