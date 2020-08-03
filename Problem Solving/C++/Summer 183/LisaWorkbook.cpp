#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the workbook function below.
int workbook(int n, int k, vector<int> arr) {
    int page = 1;
    int countSpecial = 0;
    int limit = k;
    for (int chapter = 0 ; chapter < n ; chapter++) {
        limit = k;
        for (int problem = 1 ; problem <= arr[chapter] ; problem++) {
            if (problem == page) countSpecial++;
            if (problem >= limit && problem < arr[chapter]) {
                limit += k;
                page++;
            } 
        }
        page++;
    }
    return countSpecial;
}

int main() {
    vector<int> arr = {4,2,6,1,10};
    cout << workbook(5,3,arr);
}