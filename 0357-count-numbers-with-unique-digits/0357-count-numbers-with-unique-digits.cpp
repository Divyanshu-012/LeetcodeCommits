class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=10;
        for(int i=2;i<=n;i++){
            int product=9;
            int available=9;
            for(int j=1;j<i;j++){
                product*=available;
                available--;
            }
            dp[i]=product;
        }
        int ans=-1;
        for (int i=0;i<=n;i++) ans+=dp[i];
        return ans;
    }
};