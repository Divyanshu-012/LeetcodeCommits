class Solution {
public:
    unordered_map<int, bool> dp;
    
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int totalSum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (totalSum < desiredTotal) return false;
        if (desiredTotal <= 0) return true;
        return canWinHelper(maxChoosableInteger, desiredTotal, 0);
    }

    bool canWinHelper(int maxInt, int remaining, int usedMask) {
        if (dp.count(usedMask)) return dp[usedMask];
        for (int i = 1; i <= maxInt; i++) {
            int currBit = 1 << (i - 1);
            if ((usedMask & currBit) == 0) {
                if (i >= remaining || !canWinHelper(maxInt, remaining - i, usedMask | currBit)) {
                    return dp[usedMask] = true;
                }
            }
        }
        return dp[usedMask] = false;
    }
};