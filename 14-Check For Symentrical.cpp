bool fun(TreeNode* l,TreeNode* r)
    {
        if(l==NULL && r==NULL) return 1; 
        if(l==NULL || r==NULL) return 0; 
        if(l->val!=r->val) return 0; 

        return fun(l->left,r->right) && fun(l->right,r->left); 
    }
    bool isSymmetric(TreeNode* root)
    {
            if(root==NULL) return 0; 
            return fun(root->left,root->right);     
    }
