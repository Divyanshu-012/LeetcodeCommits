class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> freq;
        int maxFreq = 0;
        int maxLen = 0;
        int l = 0;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            freq[c]++;
            maxFreq = max(maxFreq, freq[c]); 

            
            while((r - l + 1) - maxFreq > k){
                freq[s[l]]--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1); 
        }

        return maxLen;
    }
};
