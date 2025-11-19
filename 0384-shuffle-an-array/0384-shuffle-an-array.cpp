class Solution {
public:
    vector<int> v;
    Solution(vector<int>& nums) {
        v=nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int> v1=v;
        for(int i=v1.size()-1;i>=0;i--)
        {
            int j = rand()%(i+1);
            swap(v1[i],v1[j]);
        }
        return v1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */