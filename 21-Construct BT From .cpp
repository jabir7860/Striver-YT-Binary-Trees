// Inorder 
int find_position(int in[],int &ele,int start,int end){
        for(int i=start;i<=end;i++){
            if(in[i]==ele)
            return i;
        }
        return -1;
    }
    
    Node* buildTree(int inorder[],int preorder[], int n)
    {
        
        Node * root = buildTree(preorder,0,n-1,inorder,0,n-1);
        return root;
        
    }
    Node * buildTree(int preorder[],int preStart, int preEnd,
    int inorder[],int inStart,int inEnd){
        if(preStart>preEnd || inStart>inEnd)return NULL;

       Node * root  = new Node(preorder[preStart]);

        int inRoot = find_position(inorder,root->data,inStart,inEnd);
        int numsLeft = inRoot-inStart;

        root->left = buildTree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inRoot-1);
        root->right =buildTree(preorder,preStart+numsLeft+1,preEnd,inorder,inRoot+1,inEnd);

        return root;
    }
