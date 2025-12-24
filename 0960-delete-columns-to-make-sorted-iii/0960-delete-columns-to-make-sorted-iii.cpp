class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs[0].size();
        int n = strs.size();
        vector<int> dp(m,1);
        //dp[i] = lis ending at index i
        for(int i=1;i<m;i++){
            for(int j=0;j<i;j++){
                bool flag = true;
                for(int k=0;k<n;k++){
                    if(strs[k][j] > strs[k][i]){
                        //this col. can't be extended
                        flag = false;
                        break;
                    }
                }
                if(flag)dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return m-*max_element(dp.begin(),dp.end());
    }
};