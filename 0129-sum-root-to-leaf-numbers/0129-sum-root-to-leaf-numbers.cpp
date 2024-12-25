/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<int>v;
public:
    void helper(TreeNode*root,int k){
        int n=k*10+root->val;
        if(root->left==nullptr and root->right==nullptr){
            v.push_back(n);
            return;
        }
        if(root->left) helper(root->left,n);
        if(root->right) helper(root->right,n);

    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        int ans{};
        for(auto&i:v)ans+=i;
        return ans;
    }
};