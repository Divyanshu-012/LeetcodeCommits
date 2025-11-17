class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<32; i++) {
            int count = 0;
            int mask = 1<<i;
            for(int num: nums) {
                if(num & mask)  count++;
            }
            if (count%3) res = res|mask;
        }
        return res;
    }
};