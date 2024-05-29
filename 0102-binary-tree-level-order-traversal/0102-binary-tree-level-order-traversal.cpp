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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int> v(q.size(),-1);
            for(int i=0;i<v.size();i++){
                auto it=q.front();
                q.pop();
                v[i]=it->val;
                if(it->left)q.push(it->left);
                if(it->right)q.push(it->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};