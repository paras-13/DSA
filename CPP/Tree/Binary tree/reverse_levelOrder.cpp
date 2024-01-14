// Reverse Level Order Traversal
/*
Complexity:   Time:- O(n),    Space: O(n)*/
// Using stack and queue
#include <iostream>
#include <stack>
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
        right = left = NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root == NULL) return new Node(val);
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        else
        {
            temp->left = new Node(val);
            return root;
        }
        if(temp->right!=NULL) q.push(temp->right);
        else
        {
            temp->right = new Node(val);
            return root;
        }
    }
    return root;
}

void levelorder(Node* root)
{
    if(root == NULL) return;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
}

void reverse_levelOrder(Node* root)
{
    if(root == NULL) return;
    stack <Node*> st;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        st.push(temp);
        if(temp->right!=NULL) q.push(temp->right);
        if(temp->left!=NULL) q.push(temp->left);
    }

    while(!st.empty())
    {
        cout << st.top()->data << " ";
        st.pop();
    }
}
int main()
{
    Node* root = NULL;
    int n, val;
    cout << "Enter total number of elements: ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Forward: ";
    levelorder(root);
    cout << endl << "Reverse: ";
    reverse_levelOrder(root);
}
