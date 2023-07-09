https://leetcode.com/problems/maximum-width-of-binary-tree/ 


 int widthOfBinaryTree(TreeNode* root) {
          if(!root)return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        while(!q.empty())
        {
            int size=q.size();
            int first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front().first;
                int cur_id=q.front().second; 
                if(i==0)first=q.front().second; 
                if(i==size-1)last=q.front().second; 
                q.pop(); 

                if(node->left){
                    q.push({node->left,(long long)2*cur_id+1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*cur_id+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    } 
