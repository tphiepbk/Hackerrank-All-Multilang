#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
	    Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

               return root;
           }
        }
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if (root == NULL) return -1;
        static int maxHeight = 0;
        int leftHeight = 1 + height(root->left);
        int rightHeight = 1 + height(root->right);
        if (leftHeight >= rightHeight) return leftHeight;
        else return rightHeight;
    }

    void verticalTraversal(Node* root, int index, map<int, vector<int>> &m) {
        if (root == NULL) return;
        m[index].push_back(root->data);
        verticalTraversal(root->left, index-1, m);
        verticalTraversal(root->right, index+1, m);
    }

    void getLevel(Node* root, int level, map<int, int>& m2) {
        if (root == NULL) return;
        m2.insert(pair<int, int>(root->data, level));
        getLevel(root->left, level+1, m2);
        getLevel(root->right, level+1, m2);
    }

    void topView(Node* root) {
        map<int, vector<int>> m;
        map<int, int> m2;
        getLevel(root, 0, m2);
        verticalTraversal(root, 0, m);
        map<int, vector<int>>::iterator it;
        for (auto it = m.begin() ; it != m.end() ; ++it) {
            vector<int> line = it->second;
            int minLevel = m2.size(); // Level is higher when smaller
            int minIndex = 0; // Correspond to minLevel
            for (int i = 0 ; i < line.size() ; i++) {
                int temp = m2.find(line[i])->second; // Get level of current node
                if (temp < minLevel) { // If level is less than maxLevel
                    minLevel = temp;
                    minIndex = i;
                } 
            }
            cout << line[minIndex] << " ";
        }
    } 

    Node* lca(Node* root, int v1, int v2) {
        vector<int> seq1;
        vector<int> seq2;
        Node* walker = root;
        while (true) {
            seq1.push_back(walker->data);
            if (walker->data == v1) break;
            if (v1 < walker->data) {
                walker = walker->left;
            }
            else walker = walker->right;
        }
        walker = root;
            while (true) {
            seq2.push_back(walker->data);
            if (walker->data == v2) break;
            if (v2 < walker->data) {
                walker = walker->left;
            }
            else walker = walker->right;
        }

        int size = 0;
        if (seq1.size() < seq2.size()) size = seq1.size();
        else size = seq2.size();

        int res = 0;
        for (int i = size-1 ; i >= 0 ; i--) {
            if (seq1[i] == seq2[i]) {
                res = seq1[i];
                break;
            }
        } 

        walker = root;
        while (walker->data != res) {
            if (res < walker->data) walker = walker->left;
            else walker = walker->right;
        }

        return walker;
    }

	bool checkBST(Node* root) {
		if (root == NULL) return true;
        if (root->right != NULL && root->right->data < root->data) return false;
        if (root->left != NULL && root->left->data >= root->data) return false;
        return (checkBST(root->left) & checkBST(root->right));
    }

    void checkBSTUltility(Node* root, vector<int>& v) {
        if (root != NULL) {
            checkBSTUltility(root->left,v);
            v.push_back(root->data);
            checkBSTUltility(root->right, v);
        } 
    }     

	bool checkBST(Node* root) {
        vector<int> v;
        checkBSTUltility(root, v);
        for (int i = 0 ; i < v.size() - 1; i++) {
            if (v[i+1] <= v[i]) return false;
        }
        return true;
    }

}; //End of Solution

int main() {
    
    // Solution myTree;
    // Node* root = NULL;
    
    // int t;
    // int data;

    // //std::cin >> t;

    // //while(t-- > 0) {
    // //    std::cin >> data;
    // //    root = myTree.insert(root, data);
    // //}
    
    // //myTree.topView(root);

    // //int height = myTree.height(root);
    // //std::cout << height;

    // //myTree.lca(root,1,7);

    Solution myTree2;
    Node* root = NULL;
    root = new Node(6);
    root->left = new Node(4);
    root->right = new Node(8);
    root->right->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(9);

    bool check = myTree2.checkBST(root);
    cout << check;

    return 0;
}