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

void insertionSort1(int n, vector<int> arr) {
    int rightmost = arr[n-1];
    for (int i = n-1 ; i >= 0 ; i--) {
        if (i == 0) {
            arr[i] = rightmost;
            printStep(arr);
            return;
        }
        if (arr[i-1] > rightmost) {
            arr[i] = arr[i-1];
            printStep(arr);
        }
        else {
            arr[i] = rightmost;
            printStep(arr);
            return;
        }
    }
}

void insertionSort2(int n, vector<int> arr) {
    
}

int main() {
    vector<int> arr = {2,3,4,5,6,7,8,9,10,1};
    vector<int> arr2 = {1,2,4,5,3};
    insertionSort1(10,arr);
    return 0;
}