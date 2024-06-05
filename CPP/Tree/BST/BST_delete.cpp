#include <iostream>
#include <queue>
using namespace std;
class TreeNode {
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val) {
        data = val;
        right = left = NULL;
    }
};

TreeNode* insertNode(TreeNode* root, int val) {
    if(root == NULL)
    {
       root = new TreeNode(val);
       return root;
    }
    if(root->data > val) 
        root->left = insertNode(root->left, val);
    if(root->data < val)
        root->right = insertNode(root->right, val);
    return root;
}

TreeNode* deleteNode(TreeNode* root, key) {
    if(root == NULL) return root;
    if(root->data > val) {
        root->left = deleteNode(root->left, key);
        return root;
    }
    if(root->data < val {
        root->right = deleteNode(root->right, key);
        return root;
    }
    if(root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
    }
    else {
        
    }
}
void levelOrder(TreeNode* root) {
    if(root == NULL) return;
    queue <TreeNode* >q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) q.push(NULL);
        }
        if(temp) {
            cout << temp -> data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}
void inorder(TreeNode* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main() {
    TreeNode* root = NULL;
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int val;
    for(int i=0; i<n; i++) {
        cin >> val;
        root = insertNode(root, val);
    }
    inorder(root);
    levelOrder(root);
}
