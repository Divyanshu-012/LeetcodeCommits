class Solution {
public:
    int trailingZeroes(int n) {
        int ans =0;
        ans += n/5 + n/25+ n/125+n/625+n/3125;
        return ans;
    }
};