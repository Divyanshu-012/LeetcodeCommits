class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, j = 0;
        
        deque<int> dq;
        vector<int> ans;
 
        while (j < nums.size()) {
            while (!dq.empty() and nums[j] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(j);

            if (j - i + 1 < k) { j++; continue; }

            ans.push_back(nums[dq.front()]);

            // handling the transition
            if (i == dq.front()) dq.pop_front();

            i++;
            j++;
        }

        return (ans);
    }
};