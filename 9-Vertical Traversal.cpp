https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1 

https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/


vector<vector<int>> verticalTraversal(TreeNode* root) {
      queue<pair<TreeNode*,pair<int,int>>>q;
map<int,map<int,multiset<int>>>mp;
q.push({root,{0,0}});
while(!q.empty())
{
auto it=q.front();
q.pop();
TreeNode*node=it.first;
int x=it.second.first;
int y=it.second.second;
mp[x][y].insert(node->val);
if(node->left)
{
q.push({node->left,{x-1,y+1}});
}
if(node->right)
{
q.push({node->right,{x+1,y+1}});
}
}
vector<vector<int>>ans;
for(auto it:mp)
{
vector<int>v;
for(auto ik:it.second)
{
v.insert(v.end(),ik.second.begin(),ik.second.end());
}
ans.push_back(v);
}
return ans;
    }
