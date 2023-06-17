 vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; 
        if(root==NULL) return ans;
        queue<TreeNode*>q; 
        q.push(root);  
        int i=0; 
        while(!q.empty())
        {
            vector<int>a; 
            int k=q.size();
            
            while(k--)
            {
                TreeNode* curr=q.front(); 
                q.pop();
                a.push_back(curr->val);
                if(curr->left) q.push(curr->left); 
                if(curr->right) q.push(curr->right); 
            }
            if(i++%2!=0) 
            {
                reverse(a.begin(),a.end()); 
            }
            ans.push_back(a); 
        }
        return ans; 
    }
