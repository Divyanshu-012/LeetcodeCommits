/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return (std::max(lh, rh) + 1);
    }
    void reverseLevelOrder(TreeNode* root, int level, int depth,
                           vector<int>& sub) {
        if (root) {
            reverseLevelOrder(root->left, level + 1, depth, sub);
            if (level == depth)
                sub.push_back(root->val);
            reverseLevelOrder(root->right, level + 1, depth, sub);
        }
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> array;
        int depth = height(root) - 1;
        for (int d = depth; d >= 0; d--) {
            vector<int> sub;
            reverseLevelOrder(root, 0, d, sub);
            array.push_back(sub);
        }
        return array;
    }
};