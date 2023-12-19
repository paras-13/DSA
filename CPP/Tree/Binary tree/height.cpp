// Height of Binary tree
// Using two approaches:- 
// 1) Recursively (DFS)
// 2) Using queue (BFS)
// Both have same complexity's
/*
Time Complexity: O[n]
Space: O[n]*/
#include <iostream>
#include <queue>
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val)
{
    Node* newnode = new Node();
    newnode->data = val;
    newnode->right=newnode->left=NULL;
    return newnode;
}

// Recursive approach [DFS]Depth First Search
int height_dfs(Node* root)
{
    if(root == NULL) return 0;
    else
    {
        int left_height = height_dfs(root->left);
        int right_height = height_dfs(root->right);
        if(left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

// Using LevelOrder [BFS]Breadth First Search
int height_bfs(Node* root)
{
    int height=0;
    queue <Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();             
        if(temp==NULL) height++;
        if(temp!=NULL)
        {
            if(temp->left!=NULL) 
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        else if(!q.empty())
            q.push(NULL);
    }
    return height;
}
int main()
{
    Node* root=createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(4);
    root->left->left = createNode(5);
    root->right->left = createNode(6);
    root->left->left->right = createNode(7);
    root->left->right->left = createNode(8);
    root->left->right->left->right = createNode(9);

    cout << "Height of Binary Tree: ";
    cout << height_dfs(root) << " " << height_bfs(root);
}