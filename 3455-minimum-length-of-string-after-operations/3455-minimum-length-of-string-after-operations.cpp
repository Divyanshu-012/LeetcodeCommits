class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        unordered_map<int,int> mp;

        for(int i = 0 ; i< n ; i++){
            mp[s[i]]++;
        }
        int sum= 0;
        for(auto it : mp){
            if(it.second > 2){
                if(it.second %2 != 0){
                sum += 1;
                }else sum+=2;

            }
            
            if(it.second <= 2){
                sum += it.second;
            }
    }

        return sum;
       
    }
};