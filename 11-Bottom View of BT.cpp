https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1 

vector <int> bottomView(Node *root) {
        vector<int>ans; 
        if(root==NULL) return ans; 
        map<int,int>mpp; // stores vertex with nodes values; 
        queue<pair<Node*,int>>q; 
        q.push({root,0}); 
        while(!q.empty())
        {
            auto it=q.front(); 
            q.pop(); 
            Node* node=it.first; 
            int line=it.second; 
            mpp[line]=node->data; 
            if(node->left) q.push({node->left,line-1}); 
            if(node->right) q.push({node->right,line+1}) ;
        }
        for(auto i:mpp) ans.push_back(i.second); 
        return ans; 
    }
