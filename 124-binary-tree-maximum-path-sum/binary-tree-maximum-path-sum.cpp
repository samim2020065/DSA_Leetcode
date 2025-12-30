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
    int maxPathSum(TreeNode* root) {
        int mx=INT_MIN;
        maxPathDown(root,mx);
        return mx;
    }
    int maxPathDown(TreeNode* root,int &mx){
        if(!root){
            return 0;
        }
        int left=maxPathDown(root->left,mx);
        int right=maxPathDown(root->right,mx);
        mx=max(mx,left+right+root->val);
        return max(0,root->val+max(left,right));
    }
};