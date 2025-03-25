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
    vector<TreeNode *>buildTree(int start,int end){
        if(start > end) return {nullptr};
        vector<TreeNode *>res;
        for(int root = start;root <= end;root++){
            vector<TreeNode *>left = buildTree(start,root-1);
            vector<TreeNode *>right = buildTree(root+1,end);
            for(auto &&l:left){
                for(auto &&r:right){
                    res.push_back(new TreeNode(root,l,r));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        return buildTree(1,n);
    }
};