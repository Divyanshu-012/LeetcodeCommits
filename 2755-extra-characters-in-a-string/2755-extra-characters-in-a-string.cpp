class Solution {
public:
    int function(int i , string s, unordered_set<string>& st,int &n, vector<int>&memo){
        
        if(i >= n){
            return 0 ;
        }

        if(memo[i] != -1){
            return memo[i];
        }
        
        int result  =  1 + function(i+1,s,st,n,memo);

        for(int j = i;j<n;j++){
            string curr = s.substr(i,j-i+1);
            if(st.count(curr)){
                result = min(result,function(j+1,s,st,n,memo));
            }

        }

        return memo[i] = result;
        

    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int  n = s.length();
        vector<int>memo(n,-1);
        unordered_set<string>st(begin(dictionary),end(dictionary));
        return function(0,s,st,n,memo);
        
        
    }
};