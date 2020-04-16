#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> permutationEquation(vector<int> p) {
    vector<int> res;
    vector<int> pos(p.size());
    int temp = 0;
    vector<int> posOfPos;
    vector<int>::iterator it;
    int count = 1;
    for (int x = 0 ; x < p.size() ; x++) {
        pos[p[x] - 1] =  x + 1;
    }
    for (int x = 0 ; x < pos.size() ; x++) {
        for (int i = 0 ; i < p.size() ; i++) {
            if (pos[x] == p[i]) res.push_back(i+1);
        }
    }
    return res;
}

int main() {
    vector<int>p = {4,3,5,1,2};
    vector<int> res = permutationEquation(p);
}