//LC 104 - Maximum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int mx = 0;
    
    int maxDepth(TreeNode* root) {
        if(root != NULL)
            dfs(root,1);
        return mx;
    }
    
    void dfs(TreeNode* root, int deep){
        if(deep > mx)
            mx = deep;
        
        if(root->left != NULL)
            dfs(root->left, deep+1);
        if(root->right != NULL)
            dfs(root->right, deep+1);
        return;
    }
};
