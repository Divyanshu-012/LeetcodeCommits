class Solution {
public:
    int numWaterBottles(int numBs, int numEx) {
        int ans = numBs;

        while(numBs >= numEx){
            if((numBs % numEx )== 0){
                numBs = numBs/numEx;
                ans += numBs;
            }else{
                
                ans += numBs/numEx;
                numBs = numBs%numEx + numBs/numEx;

            }
        }
        return ans;
    }
};