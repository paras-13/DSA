// Spiral or Zigzag Level Order Traversal in Binary tree
/*
Complexity-->
                Time = O(n)
                Space = O(n
)*/
#include <iostream>
#include <queue>
#include <stack>
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
        if(temp->left != NULL)
            q.push(temp->left);
        else{
            temp->left = new Node(val);
            return root;
        }
        if(temp->right!= NULL)
            q.push(temp->right);
        else{
            temp->right = new Node(val);
            return root;
        }
    }
    return root;
}

void levelOrder(Node* root)
{
    if(root == NULL) return;
    queue<Node*> q;
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

// Using stack
void spiralOrder_stack(Node* root)
{
    if(root == NULL) return;

    stack<Node*> st1;   // Print right to left
    stack<Node*> st2;   // Print left to right
    st1.push(root);
    bool flag=true;
    while(!st1.empty()) {
        Node* temp = st1.top();
        st1.pop();
        if(temp) {
            cout << temp->data << " ";
            if(flag) {
                if(temp->left) st2.push(temp->left);
                if(temp->right) st2.push(temp->right);
            }
            else {
                if(temp->right) st2.push(temp->right);
                if(temp->left) st2.push(temp->left);
            }
        }
        if(st1.empty()) {
            flag = !flag;
            swap(st1, st2);
        }
    }

}

int main()
{
    Node* root = NULL;
    int n, val;
    cout << "Total elements to enter: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    levelOrder(root); cout << endl;
    cout << "In spiral order: ";
    spiralOrder_stack(root);
}
