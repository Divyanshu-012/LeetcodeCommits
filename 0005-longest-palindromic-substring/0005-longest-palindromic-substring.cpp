class Solution {
public:
    bool solve(int i , int j, string &s){
       if(i>=j)return true;

      if(s[i] == s[j])return solve(i+1,j-1,s);

      return false;

    }
    string longestPalindrome(string s) {
      int n =s.size();
      int max_ln = INT_MIN;
      // string ans = "";
      int sp = 0;
        for(int i = 0 ;i<n;i++){
          for(int j = i;j<n;j++){
            
            if(solve(i,j,s)){
              if((j-i+1) > max_ln){
                sp = i;
                max_ln = j-i+1;
                
              }
            }
          }
        }
        return s.substr(sp,max_ln);
    }
};