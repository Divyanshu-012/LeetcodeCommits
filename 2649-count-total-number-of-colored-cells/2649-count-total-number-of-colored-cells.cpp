class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long add = 4;

        
        if(n>1){
            for(int i = 1; i< n ; i++){
                ans = ans + add;
                add =  add + 4;

            }
        }
        
        

        return ans;
    }
};