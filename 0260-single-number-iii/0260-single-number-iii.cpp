class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xor_ = 0;

        for (int x: nums) {
            xor_ ^= x;
        }

        int ct = 0, diff;
        while (xor_) {
            if (xor_ & 1) {
                diff = 1 << ct;
                break;
            } else {
                ct++;
                xor_ /= 2;
            }
        }

        int num1 = 0, num2 = 0;
        for (int x: nums) {
            if (diff & x) {
                num1 ^= x;
            } else {
                num2 ^= x;
            }
        }
        return {num1, num2};
    }
};