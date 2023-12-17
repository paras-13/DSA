// Inserting element in a Binary Tree using Levelorder(BFS)

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
        right=left=NULL;
    }
};

Node* insertNode(Node* root, int val)
{
    if(root == NULL)
    {
        root = new Node(val);
        return root;
    }

    queue <Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp->left!=NULL)
            q.push(temp->left);
        else
        {
            temp->left =  new Node(val);
            return root;
        }
        if(temp->right!=NULL)
            q.push(temp->right);
        else
        {
            temp->right = new Node(val);
            return root;
        }
    }
    return root;
}

void levelOrder(Node* root)
{
    queue <Node*> q;
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
    // Creating nodes
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Inserting nodes
    int n, val;
    cout << "Total elements to insert: ";
    cin >>n;
    cout << "Enter elements: ";
    for(int i=0; i<n;  i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << endl << "Traversal Level Order: ";
    levelOrder(root);
    
}