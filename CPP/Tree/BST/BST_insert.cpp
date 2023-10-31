// Inserting element in a Binary Search Tree

/*
 ** Time Complexity == O(h) here h is height of tree;
                       Worst case complexity O(n);
 ** Space Complexity O(1);
*/
#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* right;
    Node* left;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    if(root->data > val) root->left =  insertNode(root->left, val);
    else if(root->data < val) root->right =  insertNode(root->right, val);
    return root;
}

void inorder(Node* root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node* root = NULL;
    int n, val;
    cout << "Enter of elements you want to enter: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    inorder(root);
}