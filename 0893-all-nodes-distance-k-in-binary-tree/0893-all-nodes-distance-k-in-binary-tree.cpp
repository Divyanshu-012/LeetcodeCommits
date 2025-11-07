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
    unordered_map<TreeNode*,TreeNode*>parent;

    void inorder(TreeNode* root){
        if(!root) return;

        if(root->left != NULL){
            parent[root->left] = root;
        }
        inorder(root->left);

        if(root->right != NULL){
            parent[root->right] = root;
        }
        inorder(root->right);
    }

    void BFS(TreeNode* target, int k, vector<int>&result){
        queue<TreeNode*>que;

        que.push(target);

        unordered_set<int>vis;

        vis.insert(target->val);

        while(!que.empty()){
            int n = que.size();

            if(k == 0) break;

            while(n--){
                TreeNode* curr = que.front();
                que.pop();
                //left
                if(curr->left != NULL && !vis.count(curr->left->val)){
                    que.push(curr->left);
                    vis.insert(curr->left->val);
                }
                //right
                if(curr->right != NULL && !vis.count(curr->right->val)){
                    que.push(curr->right);
                    vis.insert(curr->right->val);
                }

                //parent
                if(parent.count(curr) && !vis.count(parent[curr]->val)){
                    que.push(parent[curr]);
                    vis.insert(parent[curr]->val);
                }
                
            }
            k--;
        }

        while(!que.empty()){
            TreeNode* temp = que.front();
            que.pop();
            result.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>result;

        inorder(root);
        BFS(target,k,result);

        return result;
    }
};