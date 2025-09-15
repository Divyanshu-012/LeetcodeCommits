class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char>st;
        for(int i =0;i<brokenLetters.size();i++){
            st.insert(brokenLetters[i]);
        }
        int ans= 0;
        int cnt =0;
        int i =0;
        int n = text.size();
        while(i<n){
            while(text[i] != ' ' && i<n){
                if(st.find(text[i]) != st.end()){
                    cnt++;
                }
                i++;
            }

            if(cnt == 0) ans+=1;
            cnt=0;
            i++;
        }
            
        
        return ans;
    }
};