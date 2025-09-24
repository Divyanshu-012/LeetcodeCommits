class Solution {
public:
int S;
    int fn(vector<int>& arr,int target,int idx,int currSum,vector<vector<int>>&dp){
        int n = arr.size();
        if(idx == n){
            if(currSum == target ) return 1;
           
            else return 0;
        }  
        
        if(dp[idx][currSum+S] != -1) return dp[idx][currSum+S];

        int minus = fn(arr,target,idx+1,currSum-arr[idx],dp);
        
        
        int plus = fn(arr,target,idx+1,currSum+arr[idx],dp);
        
        
        return dp[idx][currSum+S] = (plus+minus);
    }
    int findTargetSumWays(vector<int>& arr, int target) {
        int n = arr.size();
        S = accumulate(arr.begin(), arr.end(), 0);
        
        
        
        vector<vector<int>>dp(n+1,vector<int>(2*S+1,-1));
        
        return fn(arr, target, 0,0,dp);
        
    }
    
};