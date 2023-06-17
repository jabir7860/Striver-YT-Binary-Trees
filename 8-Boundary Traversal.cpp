 bool isleaf(Node* root)
    {
        if(root->left==NULL && root->right==NULL) return 1; 
        return 0; 
    }
public:

    void addleftNodes(Node* root,vector<int>&res)
    {
        Node* curr=root->left; 
        while(curr)
        {
            if(!isleaf(curr)) 
                res.push_back(curr->data); 
            if(curr->left) curr=curr->left; 
            else curr=curr->right; 
        }
    }
public:

    void addleafNodes(Node* root,vector<int>&res)
    {
        if(isleaf(root)) 
        {
            res.push_back(root->data);
            return ; 
        }
        if(root->left) addleafNodes(root->left,res); 
        if(root->right) addleafNodes(root->right,res); 
    }
public:

    void addrightNodes(Node* root,vector<int>&res)
    {
        vector<int>temp; 
        Node* curr=root->right; 
        while(curr)
        {
            if(!isleaf(curr)) temp.push_back(curr->data); 
            if(curr->right) curr=curr->right; 
            else  curr=curr->left; 
        }
        for(int i=temp.size()-1;i>=0;i--) res.push_back(temp[i]); 
    }
    public :
    vector <int> boundary(Node *root)
    {
        vector<int>res; 
        if(!root) return res; 
        if(!isleaf(root)) res.push_back(root->data); 
        addleftNodes(root,res); 
        addleafNodes(root,res); 
        addrightNodes(root,res); 
        return res; 
    }
