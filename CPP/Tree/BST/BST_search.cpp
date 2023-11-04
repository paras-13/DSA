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
        right = left = NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root==NULL) return new Node(val);
    if(root->data > val) root->left = insertNode(root->left, val);
    else if(root->data < val) root->right = insertNode(root->right, val);
    return root;
}

Node* searchNode(Node* root, int key)
{
    if(root == NULL) return root; 
    if(root->data == key) return root; 
    if(root->data > key) return searchNode(root->left, key); 
    return searchNode(root->right, key);
}

int main()
{
    Node* root = NULL;
    int n, val, key;
    cout << "Enter number of elements you want to enter: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Enter element to search: ";
    cin >> key;
    if(searchNode(root, key) == NULL) cout << key << " not found\n";
    else cout << key << " found\n";
    return 0;
}