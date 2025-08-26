class Solution {
public:
    bool allZero(vector<int> counter){
        for(int &i : counter){
            if(i != 0)return false;
            
            
        }
        return true;
    }
    vector<int> findAnagrams(string txt, string pat) {
        // code here
        int n = txt.size();
        
        vector<int> counter(26,0);
        
        for(int i = 0; i<pat.length();i++){
            char ch = pat[i];
            
            counter[ch-'a']++;
        }
        
        int i = 0,j=0;
        
        vector<int>res;
        int k = pat.length();
        while(j<n){
            counter[txt[j]-'a']--;
            
            if(j-i+1 == k){
                if(allZero(counter)){
                    res.push_back(i);
                }
                counter[txt[i]-'a']++;
                i++;
            }
            j++;
        }
        return res;
    }
};