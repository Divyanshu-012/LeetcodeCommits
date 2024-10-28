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
    
    void largestSum(TreeNode* root, vector<long long> &sum) {
         if (!root) return;
        queue<pair<TreeNode*, int>> q;  
        q.push({root, 0});

        while(!q.empty()) {
            int levelSize = q.size();  
            long long levelSum = 0;

            for(int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                int level = q.front().second;
                q.pop();

                levelSum += node->val; 

                if(node->left != nullptr) {
                    q.push({node->left, level + 1});
                }
                if(node->right != nullptr) {
                    q.push({node->right, level + 1});
                }
            }
            sum.push_back(levelSum);  
        }
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sum; 
        largestSum(root, sum); 
        sort(sum.begin(), sum.end());  

        
        if(k > sum.size()) return -1;

        int ans = sum.size() - k ;
        return sum[ans];  
    }
};