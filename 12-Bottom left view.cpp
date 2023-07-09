https://leetcode.com/problems/find-bottom-left-tree-value/

int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q; 
        q.push(root); 
        int ans=-1; 
        while(!q.empty()) 
        {
            int n=q.size(); 
            for(int i=0;i<n;i++) 
            {
                auto it=q.front(); 
                q.pop(); 
                if(i==0) ans=it->val; 
                if(it->left) q.push(it->left); 
                if(it->right) q.push(it->right); 
            }
        }
        return ans; 
    }
