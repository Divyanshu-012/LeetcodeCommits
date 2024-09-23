class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> nodes; 
        vector<int> ans;
        queue<pair<TreeNode*, pair<int, int>>> todo;

        if (root == nullptr) return ans; 

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* temp = p.first;

            int x = p.second.first;  // Horizontal distance
            int y = p.second.second; // Level

            // Always update the rightmost node at each vertical level
            nodes[y] = temp->val;

            if (temp->left) {
                todo.push({temp->left, {x - 1, y + 1}});
            }

            if (temp->right) {
                todo.push({temp->right, {x + 1, y + 1}});
            }
        }

        // Collect the rightmost nodes in order of their x values
        for (auto it : nodes) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
