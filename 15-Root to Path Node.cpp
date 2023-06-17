/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   void helper(TreeNode* root , vector<int> &temp , vector<vector<int> > &ans){
        if(root == NULL){
            // ans.push_back(s);
            return ;
        }
        if(root -> left == NULL && root -> right == NULL){
           temp.push_back(root -> val);
           ans.push_back(temp);
           temp.pop_back();
           return;
        }
        // cout << root -> val << endl;
        temp.push_back(root->val);
        helper(root->left, temp,ans);
        helper(root->right, temp,ans);
        temp.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> temp;
        vector<vector<int>> ans;
        helper(root, temp, ans);
        vector<string> sol;
        for(auto v:ans){
            string t = "";
            for(int i=0;i<v.size()-1;i++){
                t += to_string(v[i]);
                t += "->";
            }
            t += to_string(v[v.size()-1]);
            sol.push_back(t);
        }
        return sol;
    }
}; 
