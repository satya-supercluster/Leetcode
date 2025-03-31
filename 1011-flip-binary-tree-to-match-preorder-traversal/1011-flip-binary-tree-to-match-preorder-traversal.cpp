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
    void calling(TreeNode* root, vector<int>voyage , vector<int>&ans , int &i , TreeNode* prev)
    {
        if(root==0)
        {
            return;
        }
        if(root->val != voyage[i])
        {
            if(i==0)
            {
                ans.push_back(-1);
                return;
            }
            TreeNode* v= prev->left;
            prev->left=prev->right;
            prev->right=v;
            root=prev->left;
            if(root==0 || root->val != voyage[i] || find(ans.begin(),ans.end(),prev->val)!=ans.end())
            {
                ans.clear();
                ans.push_back(-1);
                return;
            }
            else
            {
                ans.push_back(prev->val);
            }
        }
        i++;
        calling(root->left,voyage,ans,i,root);
        if(ans.size()!=0 && ans[0]==-1)
        {
            return;
        }
        calling(root->right,voyage,ans,i,root);
        if(ans.size()!=0 && ans[0]==-1)
        {
            return;
        }
    }
    
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int>ans;
        TreeNode* prev=0;
        int i=0;
        calling(root,voyage,ans,i,prev);
        return ans;
    }
};