https://practice.geeksforgeeks.org/problems/burning-tree/1

Node*  fun(Node* root,map<Node*,Node*>&Parents,int target)
    {
        queue<Node*>q; 
        q.push(root); 
        Node* Target; 
        while(!q.empty())
        {
                Node* temp=q.front();  
                if(temp->data==target) 
                {
                    Target=temp; 
                }
                q.pop(); 
                if(temp->left) 
                {
                    Parents[temp->left]=temp; 
                    q.push(temp->left); 
                }
                if(temp->right)
                {
                    Parents[temp->right]=temp; 
                    q.push(temp->right); 
                }
        }
        return Target; 
    }
    int minTime(Node* root, int target) 
    {
        map<Node*,Node*>Parents; 
        Node* Target=fun(root,Parents,target); 
        //  bfs 
        queue<Node*>q; 
        q.push(Target); 
        // 
        map<Node*,int>vis; 
        int Time=0; 
        vis[Target]=1;  
        while(!q.empty()) 
        {
            int size=q.size(); 
            int fl=0; 
            for(int i=0;i<size;i++)
            {
            auto t=q.front(); 
            q.pop(); 
            
            if(t->left && !vis[t->left]) 
            {
                fl=1; 
                vis[t->left]=1;
                q.push(t->left); 
                
            }
            if(t->right && !vis[t->right]) 
            {
                fl=1; 
                vis[t->right]=1; 
                q.push(t->right); 
            }
            if(!vis[Parents[t]] && Parents[t]) 
            {
                fl=1; 
                vis[Parents[t]]=1; 
                q.push(Parents[t]); 
            }
            }
          if(fl) Time++; 
        }
        return Time;     
    }
