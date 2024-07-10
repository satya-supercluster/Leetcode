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
    int postorder(TreeNode*root,int&ans){
        if(root==NULL) return 0;
        int coins = root->val + postorder (root->left, ans) + postorder (root->right, ans);
        coins--;
        ans += abs(coins);
        return coins;
    }
public:
    int distributeCoins(TreeNode* root) {
        int ans{};
        postorder(root,ans);
        return ans;
    }
};