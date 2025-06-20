class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end());

        int ans = 0;
        int cnt = 0;
        int n = c.size();
        

        // incase i got  FIX number 
        for(int i =0; i<n;i++){
            int fix = c[i];
            cnt = n-i;
            if(cnt >= fix) ans = max(ans,fix);
            if(fix > cnt){
                ans = max(cnt,ans);
            } 
        }

        // if(ans == 0){
        //     if(c[n-1]==0)return 0; //true always
            
        // }
        return ans;
    }
};