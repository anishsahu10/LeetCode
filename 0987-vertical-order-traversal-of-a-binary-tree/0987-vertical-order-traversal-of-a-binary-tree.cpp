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
    void preorder(TreeNode* root,int vert,int lvl,map<int,map<int,multiset<int>>> &nodes){
        if(!root) return;
        
        nodes[vert][lvl].insert(root->val);
        preorder(root->left,vert-1,lvl+1,nodes);
        preorder(root->right,vert+1,lvl+1,nodes);
    }
                  
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> nodes;
        preorder(root, 0, 0, nodes);
        vector<vector<int>> ans;
        
        for(auto p : nodes){
            vector<int> col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};