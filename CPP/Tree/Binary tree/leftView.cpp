/*
Program is to print left side view of a tree:
Methods used:-
1 Recursive
2 Iterative
Time :- O(n);
Space: O(n);
*/
#include <iostream>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node* right;
    Node* left;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
 
Node* insertNode(Node* root) {
    if(root == NULL) cout << "Enter root value: ";
    int val;
    cin >> val;
    if(val == -1) {return NULL;}
    root = new Node(val);
    
    cout << "Enter value for left node: ";
    root->left = insertNode(root);
    
    cout << "Enter value for right node: ";
    root->right = insertNode(root);
    return root;
}
void print(Node* root) {
    if(root == NULL) return;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        if(temp) {
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
void leftViewOfTree(Node* root, int level, int* maxLevel) {
    if(root == NULL) return;
    if(*maxLevel < level) {
    cout << root->data << " ";
    *maxLevel = level;
    }
    leftViewOfTree(root->left, level+1, maxLevel);
    leftViewOfTree(root->right, level+1, maxLevel);
}
void leftViewOfTree(Node* root) {
    if(root == NULL) return;
    queue <Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        for(int i=0; i<size; i++) {
            Node* temp = q.front();
            q.pop();
            if(i == 0) cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
int main() {
    Node* root = NULL;
    root = insertNode(root);
    print(root);
    int max = 0;
    cout  << "Using recursive approach: ";
    leftViewOfTree(root, 1, &max); // Recursive Approach
    // Iterative Approach
    cout << endl << "Using Iterative approach: ";
    leftViewOfTree(root);
}