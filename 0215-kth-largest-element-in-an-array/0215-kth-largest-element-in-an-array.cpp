class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>q;
        int n = nums.size();
        int ans;

        for(int i =0 ; i<n;i++){
            q.push(nums[i]);
        }
        while(k!=0){
            ans = q.top();
            q.pop();
            k--;
        }
        return ans;
    }
};