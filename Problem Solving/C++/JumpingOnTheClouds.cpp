#include <bits/stdc++.h>

using namespace std;

// Complete the jumpingOnClouds function below.
int jumpingOnClouds(vector<int> c) {
    vector<int> res;
    int idx = 0;
    while (idx < c.size()) {
        if ((idx + 2 == c.size() - 1) || (idx + 1 == c.size() - 1) ) {
            res.push_back(c.size() - 1);
            break;
        }
        else if (c[idx + 2] == 0) {
            idx += 2;
            res.push_back(idx);
        }
        else if (c[idx + 2] == 1 && c[idx + 1] == 0) {
            idx += 1;
            res.push_back(idx);
        }
        else {
            idx--;
        }
    }
    return res.size();
}

int main() {
    vector<int> c = {0, 0, 1, 0, 0, 1, 0};
    cout << jumpingOnClouds(c);
}