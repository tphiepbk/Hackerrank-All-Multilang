#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
int findDigits(int n) {
    int count = 0;
    int digit = 0;
    int init = n;
    do {
        digit = n % 10;
        n = n / 10;
        if (digit == 0) continue;
        else if (init % digit == 0) count++;
    } while (n > 0);
    return count;
}

int main() {
    cout << findDigits(1012) << "\n";
}