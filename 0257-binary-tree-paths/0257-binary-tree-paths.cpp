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
    vector<string>v;
public:
    void helper(TreeNode*root,string s=""){
        s+="->";
        s+=to_string(root->val);
        if(root->left==nullptr and root->right==nullptr){
            v.push_back(s);
        }
        if(root->left) helper(root->left,s);
        if(root->right) helper(root->right,s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root->left==nullptr and root->right==nullptr) return {to_string(root->val)};
        if(root->left){
            helper(root->left,to_string(root->val));
        }
        if(root->right){
            helper(root->right,to_string(root->val));
        }
        return v;
    }
};