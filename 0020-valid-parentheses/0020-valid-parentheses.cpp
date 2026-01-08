class Solution {
public:
    bool isValid(string s) {
        stack<char> st; 
        if(s.size() %2 != 0)return false;
        for (char c : s) { 
            if(c == '(' || c =='{' || c =='['){
              st.push(c);
            }else if(c ==')'){
              if(st.empty() || st.top() != '(' )return false;
              st.pop();
            }else if(c == '}'){
              if( st.empty() || st.top() != '{')return false;
              st.pop();
            }else if(c == ']'){
              if( st.empty() || st.top() != '[')return false;
              st.pop();
            }
        }
        return st.empty(); 
    }
};