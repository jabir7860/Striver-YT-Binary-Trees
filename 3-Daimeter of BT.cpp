https://leetcode.com/problems/diameter-of-binary-tree/

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
    int fun(TreeNode* root,int &ans) 
    {
        if(root==NULL) return 0; 
        int left=fun(root->left,ans); 
        int right=fun(root->right,ans); 
        ans=max(ans,left+right); 
        return 1+max(left,right); 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=INT_MIN; 
        fun(root,ans); 
        return ans; 
    }
}; 
