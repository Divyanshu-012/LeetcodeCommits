
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> maxHeap(nums.begin(), nums.end());  
        for (int i = 0; i < k; ++i) {
            int max_val = maxHeap.top();  
            maxHeap.pop();                
            sum += max_val;               
            
            int new_val = ceil(max_val / 3.0);  
            maxHeap.push(new_val);        
        }
        
        return sum;
    }
};
