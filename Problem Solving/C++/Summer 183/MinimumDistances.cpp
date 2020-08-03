#include <iostream>
#include <vector>

using namespace std;

int minimumDistances(vector<int> a) {
    int min = INT_MAX;
    int check = 0;
    for (int i = 0 ; i < a.size() - 1 ; i++) {
        for (int j = i + 1 ; j < a.size() ; j++) {
            if (a[j] == a[i]) {
                if (j-i < min) min = j - i;  
                check++;
            }
        }
    }
    if (check == 0) return -1;
    return min;
}

int main() {
    vector<int> arr = {7,1, 3, 4, 1, 7};
    cout << minimumDistances(arr);
}