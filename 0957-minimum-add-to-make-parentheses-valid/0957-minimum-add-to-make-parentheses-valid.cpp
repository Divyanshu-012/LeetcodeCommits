class Solution {
public:
    int minAddToMakeValid(string s) {
        int m = 0;
        int n = 0;

        for(int i = 0 ;i<s.size();i++){
            char ch = s[i];
            if(ch == '('){
                m++;
            }
            else if(m>0){
                m--;
                
            }
            else if(ch == ')' && m == 0){
                n++;
            }

        }
        
        return abs(m+n);
        
    }
};