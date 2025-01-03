/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> q;
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        q.push(root);
        while(!q.empty())
        {
            vector<int> arr;
            int length = q.size();
            for(int i = 0;i<length;i++)
            {
                Node* curr = q.front();
                q.pop();
                arr.push_back(curr->val);
                for(Node* child : curr->children)
                {
                    q.push(child);
                }
            }
            res.push_back(arr);
        }
        return res;
    }
};