// Inorder, Preorder, Postorder and Levelorder traversal.
#include <iostream>
#include <queue>
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
        left = right = NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    if(root->data > val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

void inorder(Node* root)
{
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<" ";
}

void levelorder(Node* root)
{
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data<<" ";
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = NULL;
    int n, val;
    cout << "Enter number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Inorder Traversal: ";inorder(root);
    cout << "\nPreorder Traversal: ";preorder(root);
    cout << "\nPostorder Traversal: ";postorder(root);
    cout << "\nLevelorder Traversal: ";levelorder(root);
    
}