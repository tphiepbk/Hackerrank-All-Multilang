#include <iostream>
#include <vector>
#include <string>

using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    string vS = "";
    for (int i = 0 ; i < s.size() ; i++) {
        for (int j = 0 ; j < s[i].size() ; j++) {
            vS += to_string(s[i][j]);
        }
    }

    vector<string> data = {"816357492", "618753294", "834159672", "672159834", "438951276", "276951438", "492357816", "294753618"};

    int minCost = INT_MAX;
    for (int i = 0 ; i < data.size() ; i++) {
        int cost = 0;
        for (int j = 0 ; j < vS.length() ; j++) {
            cost += abs(vS[j] - data[i][j]);
        }
        if (cost < minCost) {
            minCost = cost;
        }
    }

    return minCost;
}

int main() {
    vector<vector<int>> arr(3, vector<int>(3, 0));
    int temp = 0;
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            cin >> temp;
            arr[i][j] = temp;
        }
    }
    cout << formingMagicSquare(arr);
}