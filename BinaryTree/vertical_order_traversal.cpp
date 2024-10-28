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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode * , pair<int,int>>> q;
        map<int , map<int,multiset<int>>> mp;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first , y = p.second.second;
            mp[x][y].insert(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node-> right , {x+1 , y+1}});

        }
        vector<vector<int>> ans;
        for(auto i:mp){
            vector<int>col;
            for(auto p: i.second){
                col.insert(col.end(),p.second.begin(),p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};