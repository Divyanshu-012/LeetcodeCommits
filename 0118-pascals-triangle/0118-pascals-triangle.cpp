class Solution {
public:
    int ans[31][31];
    vector<vector<int>> generate(int n) {
       
        int i = 0;
        
        while(i < n){
            int j = 0;   
            while(j <= i){
                if(j == 0 || j == i){
                     ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
                j++;
            }
            i++;
        }

        
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            vector<int> row;
            for(int j = 0; j <= i; j++){
                row.push_back(ans[i][j]);
            }
            res.push_back(row);
        }
        return res;
    }
};
