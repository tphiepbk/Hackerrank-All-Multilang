#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
    vector<int> station = c;
    sort(station.begin(), station.end());

    int max = 0;
    int leftPivot = 0;
    int rightPivot = 0;
    int walker = 0;
    int minDist = 0;
    int left = 0;
    int right = 0;

    for (int i = 0 ; i < n ; i++) {
        if (i == station[walker]) continue;

        if (i == 0) {
            minDist = station[0] - i;
            if (minDist >= max) max = minDist;
            continue;
        }
        else if (i == n - 1) {
            minDist = i - station[station.size() - 1];
            if (minDist >= max) max = minDist;
            continue;
        }

        if (i > station[walker]) {
            leftPivot = station[walker];
            if (walker + 1 >= station.size()) rightPivot = station[walker];
            else {
                walker++;
                rightPivot = station[walker];
            }
        }

        right = rightPivot - i;
        left = i - leftPivot;
        if (right < 0) minDist = left;
        else if (left < 0) minDist = right;
        else { 
            if (right > left) minDist = left;
            else minDist = right;
        }

        if (minDist >= max) max = minDist;
    }
    return max;
}

int main() {
    vector<int> c = {13, 1, 11, 10, 6};
    cout << flatlandSpaceStations(20,c);
}