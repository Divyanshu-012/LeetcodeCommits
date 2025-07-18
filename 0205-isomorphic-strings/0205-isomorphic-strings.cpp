class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        

        for(int i = 0 ; i < s.size() ; i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(m1.find(ch1) != m1.end()){ 
                if(ch2 != m1[ch1]){      
                    return false;
                }
            }else{                        
                if(m2.find(ch2) != m2.end()){  
                    return false;       
                }
            }
  
            m1[ch1] = ch2;
            m2[ch2] = ch1;
            
        }
        return true;
    }
};