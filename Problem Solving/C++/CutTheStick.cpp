#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> res;
    int sizeLeft = 0;
    int smallestStick = 0;
    vector<int> zeroStickPos;
    int tempMin = 0;
    while (!arr.empty()) {

        tempMin = arr[0];
        
        sizeLeft = arr.size();
        if (sizeLeft != 0) res.push_back(sizeLeft);

        for (int i = 0 ; i < arr.size() ; i++) {
            if (arr[i] < tempMin) tempMin = arr[i];
        }
        for (int j = 0 ; j < arr.size() ; j++) {
            arr[j] = arr[j] - tempMin;
            if (arr[j] == 0) zeroStickPos.push_back(j); 
        }

        int tempDelete = 0;
        while (!zeroStickPos.empty()) {
            tempDelete = zeroStickPos.back();
            arr.erase(arr.begin() + tempDelete);
            zeroStickPos.pop_back();
        }

    }
    return res;
}

int main() {
    vector<int> arr = {5, 4, 4, 2, 2, 8};
    vector<int> res = cutTheSticks(arr);
}