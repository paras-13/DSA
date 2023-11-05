// Inverting BST.

// Code -->
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
        right= NULL;
        left = NULL;
    }
};

Node* insertNode(Node* &root, int val)
{
    if(root == NULL)
    {
        root = new Node(val);
        return root;
    }
    if(root->data > val) root->left= insertNode(root->left, val);
    if(root->data < val) root->right= insertNode(root->right, val);
    return root;
}
Node* invertNode(Node* root)
{
    if(root == NULL) return root;
    Node* t_node = root->left;
    root->left = root->right;
    root->right = t_node;
    invertNode(root->left);
    invertNode(root->right);
    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node* root = NULL;
    int n, val;
    cout << "Enter number of nodes you want to create: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        insertNode(root, val);
    }
    cout << "Original: ";
    inorder(root); cout << endl;
    invertNode(root);
    cout << "After inverting: ";
    inorder(root);
}