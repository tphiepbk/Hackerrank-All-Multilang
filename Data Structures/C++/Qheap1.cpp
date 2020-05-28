#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
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

void deleteFromHeap(int val, vector<int>& h) {
    int index = 0;
    for (int i = 0 ; i < h.size() ; i++) {
        if (h[i] == val) {
            index = i;
            break;
        }
    }
    swap(index, h.size() - 1, h);

    h.pop_back();

    reHeapDown(index, h);
}


int main() {
    int Q = 0;
    cin >> Q;
    vector<int> h;
    int key = 0;
    int v = 0;
    while (Q--) {
        cin >> key;
        if (key == 1) {
            cin >> v;
            insertToHeap(v, h);
        }
        else if (key == 2) {
            cin >> v;
            deleteFromHeap(v, h);
        }
        else {
            cout << h.front() << "\n";
        }
    }
    return 0;
}