class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> store;
        for(char c : t) store[c]++;  

        int required = t.size();    
        int i = 0, j = 0;
        int minLen = INT_MAX;
        int i_ = 0;  

        while(j < s.size()){
            
            if(store[s[j]] > 0) required--;
            store[s[j]]--;   

           
            while(required == 0){
                if(j - i + 1 < minLen){
                    minLen = j - i + 1;
                    i_ = i;
                }
                store[s[i]]++;   
                if(store[s[i]] > 0) required++;  
                i++;
            }

            j++;
        }

        if(minLen == INT_MAX) return "";
        return s.substr(i_, minLen);
    }
};
