//LC 236 - Lowest Common Ancestor of a Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>

class Solution {
public:
    vector<TreeNode*> ans;
    void getRoute(TreeNode* root, TreeNode* node, vector<TreeNode*> &v){
        v.push_back(root);
        
        if(root == node){
            ans = v;
        }
        
        if(root->left != NULL){
            getRoute(root->left, node, v);
        }
        if(root->right != NULL){
            getRoute(root->right, node, v);
        }
        
        v.pop_back();        
        return;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v;
        getRoute(root, p, v);
        auto pathP = ans;
        getRoute(root, q, v);
        auto pathQ = ans;
        
        TreeNode* lca = root;
        for(int i=0; i<min(pathP.size(), pathQ.size()); i++){
            if(pathP[i] == pathQ[i])
                lca = pathP[i];
        }
        
        return lca;
    }
};
