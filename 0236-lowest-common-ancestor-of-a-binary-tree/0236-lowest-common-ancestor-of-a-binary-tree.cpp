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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL ;

        if(root==p || root==q )
            return root;

        TreeNode* lca_from_left= lowestCommonAncestor(root->left, p,q);
        TreeNode* lca_from_right= lowestCommonAncestor(root->right, p,q);

        if(lca_from_left != NULL && lca_from_right != NULL){
            return root;
        }
        if(lca_from_left != NULL) return lca_from_left;
        return lca_from_right;
        
    }
};