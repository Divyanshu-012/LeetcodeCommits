class Solution {
public:
    int t[1001][1001];
    bool solve(int i , int j, string &s){
       if(i>=j)return true;

       if(t[i][j] != -1)return t[i][j];

      if(s[i] == s[j])return solve(i+1,j-1,s);

      return false;

    }
    string longestPalindrome(string s) {
      int n =s.size();
      int max_ln = INT_MIN;
      memset(t,-1,sizeof(t));
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