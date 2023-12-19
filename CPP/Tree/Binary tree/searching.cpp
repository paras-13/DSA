/*
Time Complexity: O[n]
Space: O[n]*/
#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int x)
    {
        data = x;
        right = left = NULL;
    }
};

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left != NULL)
            q.push(temp->left);
        else
            temp->left = new Node(val);
        if (temp->right != NULL)
            q.push(temp->right);
        else
            temp->right = new Node(val);
    }
    return root;
}

int searchNode(Node *root, int key)
{
    if (root == NULL)
        return -1;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *t = q.front();
        if (t->data == key)
            return 1; // Element found
        q.pop();
        if (t->left != NULL)
            q.push(t->left);
        if (t->right != NULL)
            q.push(t->right);
    }

    return 0; // Element not found
}

int main()
{
    Node *root = NULL;
    int n, val, key;
    cout << "Total elements to enter: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Enter value to search for: ";
    cin >> key;
    int rep = searchNode(root, key);
    if (rep == 1)
        cout << "Element found" << endl;
    else if (rep == 0)
        cout << "Element not found" << endl;
    else
        cout << "Empty" << endl;

    return 0;
}
