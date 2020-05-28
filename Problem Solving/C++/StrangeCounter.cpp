#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
    long count = 0;
    long time = 1;
    long preTime = 0;
    long value = 3;
    long preValue = 0;
    while (true) {
        preTime = time;
        preValue = value;
        time = time + 3 * pow(2, count);
        value *= 2;
        count++;
        if (time > t) break;
    }
    return preValue - (t - preTime);
}

int main() {
    cout << strangeCounter(25);
}