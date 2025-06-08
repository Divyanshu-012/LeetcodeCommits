class Solution {
public:
    void dfs(int curr, int n,vector<int>&result){
        if(curr > n) return ;
        result.push_back(curr);

    //append
        for(int i =0; i<=9;i++){
            int newNo= curr*10+i;
            

            if(newNo>n){
                return ;
            }
            dfs(newNo,n,result);
        }
        
        

    }
    vector<int> lexicalOrder(int n) {
        vector<int>result;
        for(int i =1; i<=9;i++){
            dfs(i,n,result);
        }
        return result;
    }
};