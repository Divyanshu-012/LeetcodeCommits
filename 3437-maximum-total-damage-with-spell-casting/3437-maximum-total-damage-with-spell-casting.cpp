class Solution {
public:
    long long dp[100001];
    long long fun(vector<int>&v , map<int,int>&m , int in){
        if(in >= v.size()){
            return 0;
        }

        if(dp[in] != -1){
            return dp[in];
        }

        long long ans = 0 ;

        auto it = upper_bound(v.begin() , v.end() , v[in] + 2);

        if(it != v.end()){
            ans = max(ans , (long long)v[in] * (long long)m[v[in]] + fun(v , m , it - v.begin()));
        }
        else{
            ans = max(ans , (long long)v[in] * (long long)m[v[in]] );
        }

        ans = max(ans , fun(v , m , in+1));

        return dp[in] = ans;
    }
    long long maximumTotalDamage(vector<int>& power) {
        memset(dp , -1 , sizeof(dp));
        map<int,int>m;
        long long ans = 0 ;

        for(auto p : power){
            m[p]++;
        }

        vector<int>v;

        for(auto e : m){
            v.push_back(e.first);
        }

        return fun(v , m , 0);
    }
};