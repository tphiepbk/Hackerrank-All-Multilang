#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



void swap(int idx1, int idx2, vector<int>& h) {
    int temp = h[idx1];
    h[idx1] = h[idx2];
    h[idx2] = temp;
}

void reHeapUp(int child, vector<int>& h) {
    if (child == 0) return; 
    int parent = trunc((child - 1) / 2);
    if (h[parent] > h[child]) {
        swap(parent, child, h);
    }

    reHeapUp(parent, h);
}

void insertToHeap(int val, vector<int>& h) {
    h.push_back(val);
    if (h.size() != 1) reHeapUp(h.size() - 1, h);
}

void reHeapDown(int parent, vector<int> &h) {
    int leftChild = parent * 2 + 1;
    int rightChild = parent * 2 + 2;
    int smallest = 0;
    if (leftChild >= h.size() && rightChild >= h.size()) return;
    else if (leftChild >= h.size())  smallest = rightChild;
    else if (rightChild >= h.size()) smallest = leftChild;
    else {
        if (h[leftChild] < h[rightChild]) smallest = leftChild;
        else smallest = rightChild;
    }

    if (h[parent] >= h[smallest]) {
        swap(parent, smallest, h);
    }

    reHeapDown(smallest, h);
}

int popFrontHeap(vector<int>& h) {
    int res = h[0];
    swap(0, h.size() - 1, h);
    h.pop_back();
    reHeapDown(0, h);
    return res;
}

vector<int> buildHeap(vector<int> arr) {
    vector<int> res;
    while (!arr.empty()) {
        int val = arr.back();
        arr.pop_back();
        insertToHeap(val, res);
    }
    return res;
}

int cookies(int k, vector<int> A) {
    A = buildHeap(A);
    int countForOps = 0;
    int check = 0;
    while (A.size() > 1) {
        if (A.front() >= k) break;
        int candy1 = popFrontHeap(A);
        int candy2 = popFrontHeap(A);
        int mixed = candy1 + 2 * candy2;
        insertToHeap(mixed, A);
        countForOps++;
    }
    if (A.front() < k) return -1;
    return countForOps;
}

int main() {
    vector<int> A = {1,2,3,9,10,12};
    cout << cookies(7, A);
}