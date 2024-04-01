/* GFG:- Closest Neighbour in BST
*  Ques:- Given the root of a binary search tree and a number n,
*         find the greatest number in the binary search tree that is less than or equal to n. 
*/

// Code -->
#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        right = left = NULL;
    }
};

// Inserting values in BST;
Node* insertNode(Node* root, int val) {
    if(root == NULL) return new Node(val);
    if(root->data > val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}
void closestNeighbour(Node* root, int x, int &temp) {
    if(root == NULL) return;
    closestNeighbour(root->left, x, temp);
    if(root->data <= x) {
        temp = max(temp, root->data);
    }
    closestNeighbour(root->right, x, temp);
}
int main() {
    Node* root = NULL;
    int n, val, x;
    cout << "Enter the number of elements to enter:" ;
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Enter number to find closest neighbour for: ";
    cin >> x;
    int temp=-1;
    if(root == NULL) {cout << -1; return 0;}
    closestNeighbour(root, x, temp);
    cout << temp;
}