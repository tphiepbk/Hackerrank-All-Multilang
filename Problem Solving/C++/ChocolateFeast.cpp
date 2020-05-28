#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the chocolateFeast function below.
int chocolateFeast(int n, int c, int m) {
    int chocoBought = 0;
    int wrapper = 0;
    int moneyLeft = n;
    int eaten = 0;
    int chocoFree = 0;
    while (true) {
        if (moneyLeft >= n) {
            chocoBought = moneyLeft / c;
            moneyLeft = moneyLeft % c;
            eaten += chocoBought;
            wrapper = chocoBought;
        }

        chocoFree = wrapper / m;
        wrapper = wrapper % m;
        eaten += chocoFree;
        wrapper += chocoFree;

        if (wrapper < m && moneyLeft < c) break; 
    }
    return eaten;
}

int main() {
    cout << chocolateFeast(15,3,2);
}