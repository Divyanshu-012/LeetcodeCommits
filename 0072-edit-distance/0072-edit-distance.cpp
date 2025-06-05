class Solution {
public:
    int fn(int i , int j,string s, string t,vector<vector<int>>&dp) {

        if(i < 0 )return j+1;
        if(j <0) return i+1 ;

        if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j]) return 0 + fn(i-1,j-1,s,t,dp);

        return dp[i][j]= 1+ min(fn(i-1,j,s,t,dp),min(fn(i,j-1,s,t,dp),fn(i-1,j-1,s,t,dp)));
        
        
        
    }
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return fn(n-1,m-1,s,t,dp);
    }
};