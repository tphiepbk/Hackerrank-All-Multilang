#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q,numberOfElement, iIndex, jIndex;
    cin >> n >> q;
    int** arr = new int*[n];
    for (int i = 0 ; i < n ; i++) {
        cin >> numberOfElement;
        arr[i] = new int[numberOfElement];
        for (int j = 0 ; j < numberOfElement ; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0 ; i < q ; i++) {
        cin >> iIndex >> jIndex;
        cout << arr[iIndex][jIndex] << "\n";
    }
    for (int i = 0 ; i < n ; i++) delete arr[i];
    delete []arr;
    return 0;
}