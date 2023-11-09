// Find minimum element in BST:
/*
    Time complexity :- O(n) Worst case
*/
#include <iostream>
using namespace std;
class TreeNode
{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int x)
    {
        data = x;
        right = left = NULL;
    }
};

TreeNode* insertNode(TreeNode* root, int val)
{
    if(root == NULL) return new TreeNode(val);
    if(root->data > val) root->left = insertNode(root->left, val);
    else root->right = insertNode(root->right, val);
    return root;
}

int findMin(TreeNode* root)
{
    if(root == NULL) return -1;
    while(root->left!=NULL) root = root->left;
    return root->data;
}
int main()
{
    TreeNode* root = NULL;
    int n, val;
    cout << "Total elements in tree: ";
    cin >> n;
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
    {
        cin >> val;
        root = insertNode(root, val);
    }
    cout << "Minimum element of this BST is: " <<  findMin(root)<<endl;
}