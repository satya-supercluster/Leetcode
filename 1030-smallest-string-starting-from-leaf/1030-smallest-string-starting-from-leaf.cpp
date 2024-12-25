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
    string s;
    bool p=true;
public:
    string smal(string a,string b){
        if(a<b)return a;
        return b;
    }
    void helper(TreeNode*root,string s){
        s+='a'+root->val;
        if(root->left==nullptr and root->right==nullptr){
            reverse(begin(s),end(s));
            if(p){
                this->s=s;
                p=false;
            }
            else this->s=smal(s,this->s);
            cout<<s<<endl;
            cout<<this->s<<endl;
        }
        if(root->left) helper(root->left,s);
        if(root->right) helper(root->right,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string k;
        helper(root,k);
        return s;
    }
};