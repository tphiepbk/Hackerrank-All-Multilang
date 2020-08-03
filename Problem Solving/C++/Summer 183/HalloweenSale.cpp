#include <iostream>
#include <vector>

using namespace std;

int howManyGames(int p, int d, int m, int s) {
    int numOfGames = 0;
    while (true) {
        s -= p;
        if (s < 0) break;
        else numOfGames++;
        p -= d;
        if (p < m) p = m;
    }
    return numOfGames;
}

int main() {
    cout << howManyGames(20,3,6,85);
}