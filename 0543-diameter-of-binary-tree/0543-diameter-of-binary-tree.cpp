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
    int findHeight(TreeNode* root,int &diam) {
        
         if(root == NULL) {
            return 0;

        } 
        int lh = findHeight(root->left,diam);
        int rh = findHeight(root->right,diam);
        
        diam = max(diam, (lh + rh));
        return  max(lh, rh)+1 ;
 
    }
    int diameterOfBinaryTree(TreeNode* root){
        int diam=0;
        findHeight(root,diam);
        return diam;
    }
};