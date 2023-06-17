// 
    void fun(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&ParentNodes)
    {
        queue<TreeNode*>q; 
        q.push(root); 
        while(!q.empty())
        {
            TreeNode* k=q.front(); 
            q.pop(); 
            if(k->left) 
            {
                ParentNodes[k->left]=k; 
                q.push(k->left); 
            }
            if(k->right)
            {
                ParentNodes[k->right]=k; 
                q.push(k->right); 
            }
        }        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>ParentNodes; 
        fun(root,ParentNodes);  
        unordered_map<TreeNode*,bool>vis; 
        queue<TreeNode*>q; 
        q.push(target); 
        vis[target]=1; 
        int curr_size=0; 
        while(!q.empty())
        {
            int size=q.size(); 
            if(curr_size++ == k) break; 
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front(); 
                q.pop(); 
                if(temp->left && !vis[temp->left])
                {
                    vis[temp->left]=1; 
                    q.push(temp->left); 
                }
                if(temp->right && !vis[temp->right])
                {
                    vis[temp->right]=1; 
                    q.push(temp->right); 
                }
                if(ParentNodes[temp] && !vis[ParentNodes[temp]])
                {
                    vis[ParentNodes[temp]]=1; 
                    q.push(ParentNodes[temp]); 
                }
            }
        } 
        vector<int>ans; 
        while(!q.empty())
        {
            TreeNode* x=q.front(); 
            q.pop(); 
            ans.push_back(x->val); 
        }
        return ans; 
    }
};
