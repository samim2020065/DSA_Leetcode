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
    void inorder(TreeNode* root,int &element,int &ans,int &k){
        if(root==NULL){
            return;
        }
        inorder(root->left,element,ans,k);
        element++;
        if(element==k){
            ans=root->val;
        }
        inorder(root->right,element,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int element=0,ans=0;
        inorder(root,element,ans,k);
        return ans;
    }
};