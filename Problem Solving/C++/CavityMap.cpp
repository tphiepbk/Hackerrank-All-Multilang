#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    vector<string> res = grid;
    int left, right, top, bottom, center = 0;
    string aboveLine = "";
    string belowLine = "";
    string currentLine = "";
    for (int i = 1 ; i < res.size() - 1 ; i++) {
        currentLine = res[i];
        aboveLine = res[i-1];
        belowLine = res[i+1];
        for (int j = 1 ; j < currentLine.length() - 1 ; j++) {
            center = currentLine[j];
            left = currentLine[j-1];
            right = currentLine[j+1];
            top = aboveLine[j];
            bottom = belowLine[j];
            if (center > left && center > right && center > top && center > bottom) res[i][j] = 'X';
        }
    }
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    while (!result.empty()) {
        cout << result.back() << "\n";
        result.pop_back();
    }

    return 0;
}