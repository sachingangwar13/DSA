class Solution {
public:
    
    bool isleaf(Node* root){
        
        if(!root->left && !root->right) return 1;
        return 0;
    }
    
    void addLeft(Node* root , vector<int>& res){
        Node* curr = root->left;
        
        while(curr){ 
            if(!isleaf(curr)) res.push_back(curr->data);
            if(curr->left)curr = curr->left;
            else curr=curr->right;
        }
    }
    
    void addRight(Node* root , vector<int>& res){
        Node *curr = root->right;
        vector<int> temp;
        while(curr){
            if(!isleaf(curr))temp.push_back(curr->data);
            if(curr->right) curr=curr->right;
            else curr = curr->left;
        }
        
        for(int i=temp.size()-1 ; i>=0 ; i--){
            res.push_back(temp[i]);
        }
    }
    
    void addLeaves(Node* root , vector<int>& res){
        if(isleaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left)addLeaves(root->left , res);
        if(root -> right) addLeaves(root->right ,res);
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(!root)return ans;
        
        if(!isleaf(root))ans.push_back(root->data);
        
        addLeft(root,ans);
        addLeaves(root,ans);
        addRight(root , ans);
    }
};