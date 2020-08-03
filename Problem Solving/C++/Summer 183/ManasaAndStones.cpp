#include <bits/stdc++.h>

using namespace std;

// Complete the stones function below.
vector<int> stones(int n, int a, int b) {
    int temp = 0;
    int min = 0;
    int max = 0;
    if (a >= b) {
        max = a;
        min = b;
    }
    else {
        max = b;
        min = a;
    }

    int numOfMin = n-1;
    int numOfMax = 0;
    int sum = 0;
    vector<int> res;
    while (numOfMin >= 0) {
        sum = 0;
        for (int i = 0 ; i < numOfMin ; i++) {
            sum+=min;
        } 
        for (int i = 0 ; i < numOfMax ; i++) {
            sum+=max;
        }
        numOfMin--;
        numOfMax++;
        if (res.empty() || res.back() != sum) res.push_back(sum); 
    }
    return res;
}

int main() {
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> res = stones(n,a,b);
    while (!res.empty()) {
        cout << res.front() << " ";
        res.erase(res.begin());
    }
}