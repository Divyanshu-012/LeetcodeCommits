class Solution {
public:
    int strStr(string y, string d) {
        string s = "";
        int n = y.size();
        if(n < d.size()) return -1;
        int i =0,j=0;
        while(i < n){
            
            if(y[i]==d[j]){
                s+=d[j];
                i++;
                j++;
            }
                else{
                   i = i - j + 1;
                    j = 0;
                    s = "";
                }
                
            
            if(s==d) return i - d.size();
            
        }
        return -1;
    }
};