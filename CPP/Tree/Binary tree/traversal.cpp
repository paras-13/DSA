// Binary Tree Traversal

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
        data=x;
        left=right=NULL;
    }
};

void inorder(Node*root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root==NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void LevelOrder(Node* root)
{
    if(root == NULL) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);
    }
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    root->right->right->right = new Node(9);

    cout << "Level Order traversal: ";
    LevelOrder(root);
    cout <<endl;
    cout << "Inorder Traversal: ";
    inorder(root); cout << endl;
    cout << "Preorder Traversal: ";
    preorder(root); cout <<endl;
    cout << "PostOrder Traversal: ";
    postorder(root); cout << endl;
}