#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'dynamicArray' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    vector<int> q;
    int lastAnswer = 0;
    int value = 0;
    int idx = 0;
    int idx2 = 0;
    vector<int> res;
    vector<vector<int>> seqList(n);
    
    for (int i = 0 ; i < queries.size() ; i++) {
        q = queries[i];
        value = q.back();
        idx = (q[1] ^ lastAnswer) % n;
        if (q.front() == 1) {
            seqList[idx].push_back(value); 
        }
        else if (q.front() == 2) {
            idx2 = value % seqList[idx].size();
            lastAnswer = seqList[idx][idx2];
            res.push_back(lastAnswer);
        }
    }
    return res;
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> line;
    vector<long> arr(n);
    for (int i = 0 ; i < queries.size() ; i++) {
        line = queries[i];
        int begin, end;
        int sum;
        begin = line[0];
        end = line[1];
        sum = line[2];
        arr[begin-1] += sum;
        if (end < n) arr[end] -= sum;
    }
    long max = 0;
    long sum = 0;
    for (int i = 0 ; i < arr.size() ; i++) {
        sum += arr[i];
        if (sum >= max) max = sum;
    }
    return max;
}

int main() {
    vector<vector<int>> queries = {{1, 0, 5},

{1, 1, 7},

{1, 0, 3},

{2 ,1, 0},

{2, 1, 1}};
    vector<int> res = dynamicArray(2, queries);
    while (!res.empty()) {
        cout << res.front() << "\n";
        res.erase(res.begin());
    }
}