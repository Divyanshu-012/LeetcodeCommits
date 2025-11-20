class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, ele;
        //using moore's voting algorithm
        for(int i=0;i<n;i++){
            if(cnt == 0){
                ele = nums[i];
                cnt++;
            }
            else if(ele != nums[i]) cnt--;
            else cnt++;
        }
        return ele;
    }
};