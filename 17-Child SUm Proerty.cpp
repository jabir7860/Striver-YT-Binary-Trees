// Check Whether Given Binary Tree Follows Child Sum Property or Not.

 int isSumProperty(Node *root)
    {
        if(root==NULL || (root->left==NULL && root->right==NULL)) return 1;
        int sum; 
        if(root->left==NULL) sum=root->right->data; 
        if(root->right==NULL) sum=root->left->data;  
        if(root->left!=NULL && root->right!=NULL) sum=root->left->data+root->right->data; 
        if(root->data!=sum) return 0; 
        if(isSumProperty(root->left)==1 && isSumProperty(root->right)==1) return 1; 
        else return 0; 
    }
