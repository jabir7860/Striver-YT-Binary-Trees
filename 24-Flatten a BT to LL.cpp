// STRIVER
TreeNode<int> *prev=NULL; 
void fun(TreeNode<int> *root) 
{
    if(root==NULL) return ; 
    fun(root->right); 
    fun(root->left); 
    root->right=prev; 
    root->left=NULL; 
    prev=node; 
}
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root) {
    if(root==NULL) return NULL; 
    fun(root); 
    return root; 
}
// MORRIS
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)

{

    TreeNode<int>* curr = root;

    while(curr!=NULL){

        if(curr->left){

        TreeNode<int>* pred = curr->left;

            while(pred->right){

                pred = pred->right;

            }

            pred->right=curr->right;

            curr->right=curr->left;

            curr->left=NULL;

    }

    curr=curr->right;

    }

    return root;

} 

// 
