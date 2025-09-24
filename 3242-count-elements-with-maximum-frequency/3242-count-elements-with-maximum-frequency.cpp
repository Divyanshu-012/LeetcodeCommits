class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(auto i: nums){
            mp[i]++;
        }

        vector<pair<int,int>>freq(mp.begin(),mp.end());
        // sort in descending manner as per the frequency 
        sort(freq.begin(),freq.end(),[](const pair<int,int>&a,const pair<int,int>&b){
            return a.second > b.second;
        });

        int bar = freq[0].second;
        int cnt = 0;
        for(int i = 0; i<freq.size();i++){
            if(freq[i].second == bar)cnt = cnt+bar;
            else break;
        }
        return cnt;

        
    }
};