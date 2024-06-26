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
    int check(TreeNode* root) {
        if(!root) return 0;
        int lDepth = check(root->left);
        int rDepth = check(root->right);
        if(lDepth == -1 || rDepth == -1) return -1;
        if(abs(lDepth - rDepth) > 1) return -1;
        return max(lDepth, rDepth)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        if(check(root) == -1) return false;
        return true;
    }
};