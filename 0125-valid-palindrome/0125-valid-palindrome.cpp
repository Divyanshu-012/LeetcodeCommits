class Solution {
public:
    bool isPalindrome(string s) {
        vector<char>t;

        for(int  i = 0;i<s.size();i++){
            if (isalnum(s[i]))
{
    if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;

                t.push_back(s[i]);
                
            }else{
                continue;
            }
        }
        int n = t.size();
        for(int i =0  ; i< n/2;i++){
            if(t[i] != t[n-i-1]){
                return false;
            }
        }
        return true;
    }
};