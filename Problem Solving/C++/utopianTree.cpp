#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
int utopianTree(int n) {
    int init = 0;
    int count = 0;
    if (n % 2 != 0) {
        count = 2;
        init = 2;
        for (int i = 1 ; i < n ; i+=2) {
            init += pow(2,count);
            count++;
        }
    }
    else {
        init = 1;
        count = 1;
        for (int i = 0 ; i < n ; i+=2) {
            init += pow(2,count);
            count++;
        }
    }
    return init;
}
