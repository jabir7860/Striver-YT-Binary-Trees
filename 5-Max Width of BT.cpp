https://leetcode.com/problems/maximum-width-of-binary-tree/ 
 int widthOfBinaryTree(TreeNode* root) {
         if(!root)return 0;
        int ans=0;
        queue<pair<TreeNode*,int>> q;

        q.push({root,0});
        while(!q.empty()){
            int size=q.size();
            auto top=q.front();
            int min=top.second;
            int first,last;
            for(int i=0;i<size;i++){
                int cur_id=q.front().second-min;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0)first=cur_id;
                if(i==size-1)last=cur_id;

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
