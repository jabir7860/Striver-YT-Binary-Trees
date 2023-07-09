https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1


 vector<int> topView(Node *root)
    {
         vector<int>ans; 
        if(root==NULL) return ans; 
        map<int,int>mpp; 
        queue<pair<Node*,int>>q; 
        q.push({root,0}); 
        while(!q.empty())
        {
            auto p=q.front(); 
            q.pop(); 
            Node* node=p.first; 
            int line=p.second; 
            if(mpp.find(line)==mpp.end())
            {
                mpp[line]=node->data; 
            }
            if(node->left) q.push({node->left,line-1}); 
            if(node->right) q.push({node->right,line+1}); 
        }
        for(auto i:mpp) ans.push_back(i.second); 
        return ans; 
    }
