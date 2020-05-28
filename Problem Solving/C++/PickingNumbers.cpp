#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

int pickingNumbers(vector<int> a) {
    int max = 0;
    int countForLarger = 0;
    int countForSmaller = 0;
    for (int i = 0 ; i < a.size() ; i++) {
        countForLarger = 0;
        countForSmaller = 0;
        for (int j = 0 ; j < a.size() ; j++) {
            if (i == j) continue;
            if (abs(a[i] - a[j]) <= 1) {
                if (a[i] <= a[j]) countForLarger++;
                else if (a[j] <= a[i]) countForSmaller++;
            }
        }
        if (countForLarger < countForSmaller && countForSmaller >= max) max =  countForSmaller;
        else if (countForLarger >= countForSmaller && countForLarger >= max) max = countForLarger; 
    }
    return max + 1;
}

int main() {
    vector<int> a = {4, 6, 5, 3, 3, 1};
    cout << pickingNumbers(a) << "\n";
}