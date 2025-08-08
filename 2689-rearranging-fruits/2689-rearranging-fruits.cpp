class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int,int>mp;
        
        int minElm = INT_MAX;
        for(auto it : basket1){
            mp[it]++;
            minElm = min(minElm,it);
        } 
        for(auto it : basket2){
            mp[it]--;
             minElm = min(minElm,it);
        } 

        long long result = 0;
        vector<int>finallist;
        for(auto it: mp){
            int val = it.first;
            int count = it.second;

            if(count == 0) continue;
            if(count %2 != 0)return -1;

            for(int c = 1;c<=abs(count/2);c++){
                finallist.push_back(val);
            }
            
        }
        sort(finallist.begin(),finallist.end());
        for(int i = 0;i<finallist.size()/2;i++){
            result += min(finallist[i],minElm*2);
        }
        return result;

    }
};