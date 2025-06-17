class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int premin = prices[0];
        int ans =0;
        int n = prices.size();
        for(int i =1; i<n;i++){
            if(prices[i]>premin){
                ans=max(ans,prices[i]-premin);
            }else{
                premin=prices[i];
            }
        }
        // if(premin = prices[n-1]) return 0;
        return ans;
        
    }
};