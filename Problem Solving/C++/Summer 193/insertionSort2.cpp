#include <iostream>
#include <vector>

using namespace std;

void printStep(vector<int> arr) {
    while (arr.size() != 0) {
        cout << arr.front() << " ";
        arr.erase(arr.begin(), arr.begin() + 1);
    }
    cout << "\n";
}

vector<int> insertionSort1(int n, vector<int> arr) {
    int rightmost = arr[n-1];
    for (int i = n-1 ; i >= 0 ; i--) {
        if (i == 0) {
            arr[i] = rightmost;
            break;
        }
        if (arr[i-1] > rightmost) {
            arr[i] = arr[i-1];
        }
        else {
            arr[i] = rightmost;
            break;
        }
    }
    return arr;
}

void insertionSort2(int n, vector<int> arr) {
    int numOfElementInSubArray = 2;
    while (numOfElementInSubArray <= n) {
        arr = insertionSort1(numOfElementInSubArray, arr);
        printStep(arr);
        numOfElementInSubArray++;
    }
}

int main() {
    vector<int> arr = {3,4,7,5,6,2,1};
    vector<int> arr2 = {1,4,3,5,6,2};
    insertionSort2(6,arr2);
    return 0;
}