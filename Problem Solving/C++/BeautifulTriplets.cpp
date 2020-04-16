#include <iostream>
#include <vector>
#include <map>

using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    /*
    for (int i = 0 ; i < arr.size()-1 ; i++) {
        if (arr[i] == arr[i+1]) {
            arr.erase(arr.begin()+i+1);
            i--;
        }
    }
    */
    vector<vector<int>> setOfPair;
    for (int i = 0 ; i < arr.size()-1; i++) {
        for (int j = i + 1 ; j < arr.size() ; j++) {
            if (arr[j] - arr[i] == d) {
                vector<int> pair;
                pair.push_back(arr[i]);
                pair.push_back(arr[j]);
                setOfPair.push_back(pair);
                break;
            }
        }
    }
    int count = 0;
    for (int i = 0 ; i < arr.size() ; i++) {
        for (int j = 0 ; j < setOfPair.size() ; j++) {
            if (arr[i] - setOfPair[j][1] == d) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {1,2,4,5,7,8,10};
    cout << beautifulTriplets(3, arr);
}