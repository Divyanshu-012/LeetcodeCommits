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
typedef long long ll;
ll mod=1e11;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,ll>> q;
        if(root==NULL)
            return 0;
        q.push({root,1});
        ll max1=LONG_MIN;
        while(!q.empty())
        {
            ll n=q.size();
            ll i=0;
            ll mini,maxi;
            ll y=n;
            while(n--)
            {
                TreeNode* current=q.front().first;
                ll x=q.front().second;
                q.pop();
                if(i==0)
                mini=x;
                if(i==y-1)
                maxi=x;
                if(current->left)
                q.push({current->left,(2*x)%mod});
                if(current->right)
                q.push({current->right,(2*x+1)%mod});
                i++;
            }
            max1=max(maxi-mini+1,max1);
        }
        return max1;
    }
};