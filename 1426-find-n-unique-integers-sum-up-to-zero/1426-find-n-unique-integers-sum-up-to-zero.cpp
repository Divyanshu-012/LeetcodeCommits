class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n);
        int s = -(n/2);
        if(n %2 != 0){
            for(int i = 0; i<n;i++){
                ans[i]=s;
                s++;
            }
        }else{
            for(int i = 0; i<n;i++){
                if(s == 0)s=1;
                ans[i]=s;
                s++;
                
            }
        }
        
        return ans;
    }
};