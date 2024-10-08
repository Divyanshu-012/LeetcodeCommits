class Solution {
public:
    int minLength(string s) {
        string s1 = "CD";
        string s2 = "AB";

        int  i =0;
        while(i<s.size()){
            
            string currStr1 = s.substr(i, s1.size());
            string currStr2 = s.substr(i, s2.size());
            if(currStr1 == s1 || currStr2 == s2 ){
                
                s.erase(i, 2);
                if (i > 0) {
                    i--;  
                }

            }
            else{
                i++;
            }
        }

        return s.size();

    }
};