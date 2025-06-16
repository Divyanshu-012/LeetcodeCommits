class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
         vector<int>ans;
        for(int i  = d.size()-1; i>=0;i--){
            
            if(d[i]==9){
                d[i]=0;
            }else{
                d[i] = d[i]+1;
                break;
            }
           if (i == 0) {
                d.insert(d.begin(), 1);
                return d;
            }  
        }
       
        return d;
    }
};