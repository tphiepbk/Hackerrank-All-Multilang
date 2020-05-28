#include <iostream>
#include <vector>

using namespace std;

vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    vector<int>res;
    vector<int>vRank;
    int rank = 1;
    vRank.push_back(rank);
    for (int i = 1 ; i < scores.size() ; i++) {
        if (scores[i] == scores[i-1]) vRank.push_back(rank);
        else {
            rank++;
            vRank.push_back(rank);
        }
    }
    int j = 0;
    while (!alice.empty()) {
        if (alice.back() >= scores[j]) {
            alice.pop_back();
            res.insert(res.begin(), vRank[j]);
        }
        else {
            if (j == scores.size() - 1) {
                alice.pop_back();
                res.insert(res.begin(), vRank[j] + 1);
            }
            else j++;
        }
    }
    return res;
}

int main() {
    vector<int> scores = {100, 90, 90, 80, 75, 60};
    vector<int> alice = {50, 65, 77 , 90, 102};
    vector<int>res = climbingLeaderboard(scores, alice);
    for (int i = 0 ; i < res.size() ; i++) {
        cout << res[i] << "\n";
    }
}