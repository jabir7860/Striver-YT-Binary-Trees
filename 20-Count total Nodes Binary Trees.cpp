https://leetcode.com/problems/count-complete-tree-nodes/

 int countNodes(TreeNode* root) 
    {
        if(root==NULL) return 0; 
        
        return 1+countNodes(root->left)+countNodes(root->right); 
    }
