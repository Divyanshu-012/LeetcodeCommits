class Solution {
public:
    int maxConsecutiveAnswers(string ansKey, int k) {
         int i =0;
         int j = 0;
        int n = ansKey.size();
        unordered_map<char,int>mp;
        int result = 0;
         while(j<n){

            mp[ansKey[j]]++;

            while(min(mp['T'],mp['F']) > k){
                mp[ansKey[i]]--;
                i++;
            }
            result = max(result,j-i+1);
            j++;
         }
         return result;
    }
};