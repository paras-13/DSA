// Top view of a binary tree
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

vector<int> topView(TreeNode* root) {
    vector<int> res;
    queue<pair<TreeNode*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()) {
        int s = q.size();
        for(int i=0; i<s; i++) {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            q.pop();
            if(mp[level] < 1)
                mp[level] = temp->val;
            if(temp->left)
                q.push({temp->left, level-1});
            if(temp->right)
                q.push({temp->right, level+1});
        }
    }
    for(auto it : mp)
        res.push_back(it.second);
    return res;
}
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    
    // output 8 4 2 1 3 7
    vector<int> res = topView(root);
    cout << "Top view of tree: ";
    for(int it : res)
        cout << it << " ";
    return 0;
}