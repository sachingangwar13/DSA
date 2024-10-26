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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode *> q;
        vector<vector<int>> ans;
        q.push(root);
        bool ok = 1;
        while(!q.empty()){
            int n = q.size();

            vector<int> temp;
            while(n--){
                TreeNode* node = q.front();
                q.pop();

                if(node -> left != NULL)q.push(node->left);
                if(node -> right !=NULL) q.push(node ->right);
                temp.push_back(node->val);
            }
            if(ok){
                reverse(temp.begin() , temp.end());
            }
            ok = !ok;
            reverse(temp.begin() , temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};