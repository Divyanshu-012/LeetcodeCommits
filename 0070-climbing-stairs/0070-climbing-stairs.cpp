class Solution {
public:
    int climbStairs(int n) {
        int prev2 = 1;
        int prev = 1;
        if(n <= 3 ) return n;
        for(int i = 2 ; i<= n ; i++){
            int curr_i = prev + prev2;
            prev2 = prev;
            prev = curr_i;
        }
        return prev;
        
    }
};