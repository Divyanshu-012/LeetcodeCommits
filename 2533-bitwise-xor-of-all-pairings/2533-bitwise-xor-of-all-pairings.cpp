class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xor1 = 0;
        int xor2 = 0;

        int l1 = nums1.size();
        int l2 = nums2.size();

        

        if( l2 % 2 != 0){
            for(auto  i : nums1){
                xor1 ^= i;
            }
        }

        if( l1 % 2 != 0){
            for(auto  i : nums2){
                xor2 ^= i;
            }
        }
        

        return xor1 ^ xor2;

        
    }
};