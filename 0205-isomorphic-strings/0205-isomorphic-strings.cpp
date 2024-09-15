class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>m1,m2;
        

        for(int i = 0 ; i < s.size() ; i++){
            char ch1 = s[i];
            char ch2 = t[i];

            if(m1.find(ch1) != m1.end()){ // Case 1: ch1 already mapped in m1
                if(ch2 != m1[ch1]){       // Check if ch1 maps to the correct character
                    return false;
                }
            }else{                        // Case 2: ch1 is not yet mapped in m1
                if(m2.find(ch2) != m2.end()){  // Check if ch2 is already mapped to some character
                    return false;         // If so, strings aren't isomorphic
                }
            }
  
            m1[ch1] = ch2;
            m2[ch2] = ch1;
            
        }
        return true;
    }
};