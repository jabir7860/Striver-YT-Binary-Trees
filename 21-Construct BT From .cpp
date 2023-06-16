 WE Can Construct Unique inary tree only with inorder and postorder.
         Construct Unique binary tree only with inorder and preorder.

//  Constrcut  a binary tree from Inorder 
node* buildTree (int inorder[], int start, int end)
{
	if (start > end)
		return NULL;

	/* Find index of the maximum element from Binary Tree */
	int i = max (inorder, start, end);

	/* Pick the maximum value and make it root */
	node *root = newNode(inorder[i]);

	/* If this is the only element in inorder[start..end],
	then return it */
	if (start == end)
		return root;

	/* Using index in Inorder traversal, construct left and
	right subtress */
	root->left = buildTree (inorder, start, i - 1);
	root->right = buildTree (inorder, i + 1, end);

	return root;
}

/* UTILITY FUNCTIONS */
/* Function to find index of the maximum value in arr[start...end] */
int max (int arr[], int strt, int end)
{
	int i, max = arr[strt], maxind = strt;
	for(i = strt + 1; i <= end; i++)
	{
		if(arr[i] > max)
		{
			max = arr[i];
			maxind = i;
		}
	}
	return maxind;
}
// Construct a binary tree  from Inorder and  Preorder 
 TreeNode* build(vector<int>& inorder, vector<int>&preorder, int preStart, int preEnd, int inStart, int inEnd,   unordered_map < int, int > &mp){
        //base condition
        if((preStart > preEnd) || (inStart > inEnd)){
            return NULL;
        }
        int ind = mp[preorder[preStart]];
        int nelem = ind - inStart;

        TreeNode* root = new TreeNode(preorder[preStart]);
        root->left = build(inorder, preorder, preStart+1,       preStart+nelem, inStart, ind-1, mp);
        root->right= build(inorder, preorder, preStart+nelem + 1, preEnd,       ind+1,   inEnd, mp);
        return root;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preLen = preorder.size()- 1;
        int inLen  = inorder.size() - 1;
        unordered_map < int, int > mp;

        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(inorder, preorder, 0, preLen, 0, inLen, mp);
    }
// Construct a binary tree from inorder and post order. 
TreeNode* build(vector<int>&inorder, vector<int>&postorder, int is, int ie, int ps, int pe, unordered_map < int, int > &mp){
        if((ps > pe) || (is > ie))
            return NULL;
        
        int ind = mp[postorder[pe]];
        int nelem = ind - is;

        TreeNode* root = new TreeNode(postorder[pe]);
        root->left =  build(inorder, postorder,    is,  ind - 1, ps, ps + nelem - 1, mp);
        root->right = build(inorder, postorder, ind+1,  ie, ps + nelem, pe-1, mp);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postLen = postorder.size();
        int inLen = inorder.size();
        if(postLen != inLen)
            return NULL;

        unordered_map < int, int > mp;

        for(int i = 0; i < inLen; i++)
            mp[inorder[i]] = i;

        return build(inorder, postorder, 0, inLen - 1, 0, postLen - 1, mp);
    }
