// Tree Insertion using recursion: 
/*
    Time Complexity: O(n);
    Space Complexity: O(n);
*/
// Code -->
#include <iostream>
#include <queue>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
Node* insertNode(Node* root) {
    cout << "Enter val: ";
    int val;
    cin >> val;
    root = new Node(val);
    if(val == -1) {root = nullptr; return NULL;}
    else root = new Node(val);
    
    cout << "Enter value to left Node: ";   // Recursively calling for left
    root->left = insertNode(root);
    
    cout << "Enter value to right Node: ";  //  Recursively calling for right
    root->right = insertNode(root);
    return root;
}

void print(Node* root) {
    cout << endl;
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL) 
        {
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
int main() {
    Node* root = NULL;
    root = insertNode(root);
    print(root);
    return 0;
}