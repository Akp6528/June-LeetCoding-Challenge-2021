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
    
    TreeNode* build(vector<int>& pre, int s, int e, int &p, unordered_map<int, int> &mp) {
        
        if(s > e) 
            return NULL;
        if(s == e) 
            return new TreeNode(pre[p++]);
        
        int idx = 0;
        TreeNode* root = new TreeNode(pre[p]);
        idx = mp[pre[p++]];
        
        root->left = build(pre, s, idx-1, p, mp);
        root->right = build(pre, idx+1, e, p, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        
        unordered_map<int, int> mp;
        int n = in.size();
        
        for(int i=0; i<n; i++) {
            mp[in[i]] = i;
        }
        
        int p =0;
        
        return build(pre, 0, n-1, p, mp );
        
    }
};
