class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int>ans;
        
        for(int i  = 0 ; i < n ; i++ ){
            bool found = false;
            // if(i == (n-1) )  {
            //     ans.push_back(prices[i]);
            // }


            for (int j = i + 1; j < n;j++){

               

                if(prices[i] >= prices[j]){
                    int node = prices[i] - prices[j];
                    ans.push_back(node);
                    found  = true;
                    break;
                }
                // else{
                //     continue;
                // }                


            }
            if(found == false) {
                ans.push_back(prices[i]);
            }    
           
        }

        return ans;
        
    }
};