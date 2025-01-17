class Solution {
public:
    bool doesValidArrayExist(vector<int>& d) {
        if (d.size() == 1) return d[0] == 0;
        
        int n = d.size();
        vector<int> ans;
        queue<int> q;

        if (n > 1) {
            for (int i = 0; i < d.size()-1; i++) {
                if (i == 0) {
                    // Initialize the vector and queue
                    if (d[i] == 1) {
                        ans.push_back(0);
                        ans.push_back(1);
                        q.push(1);
                    } else {
                        ans.push_back(0);
                        ans.push_back(0);
                        q.push(0);
                    }
                } else {
                    // Make use of the queue to build the vector
                    if (q.front() == 1) {
                        if (d[i] == 1) {
                            ans.push_back(0);
                            q.pop();
                            q.push(0);
                        } else {
                            ans.push_back(1);
                            q.pop();
                            q.push(1);
                        }
                    } else {
                        if (d[i] == 1) {
                            ans.push_back(1);
                            q.pop();
                            q.push(1);
                        } else {
                            ans.push_back(0);
                            q.pop();
                            q.push(0);
                        }
                    }
                }
            }

            int m = ans.size();
            // Check if the last element in d matches the XOR of the last and first elements in ans
            if (d[n-1] == (ans[m-1] ^ ans[0])) {
                return true;
            } else {
                return false;
            }
        }

        return false;
    }
};
