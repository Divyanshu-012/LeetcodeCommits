class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        int n = path.size();
        int i =0;
        while(i<n){
             while (i < n && path[i] == '/') i++;
            
            string s ="";

            while(i<n && path[i]!='/'){
                s+=path[i];
                i++;
            }
            if(s == ".." ){
                if(!st.empty())
                st.pop();
            }
            else if(s=="." || s == "")continue;
            
            else{
                st.push(s);
            }
            
        }
        string ans = "";
        while (!st.empty()) {
            string top = st.top();
            st.pop();
            ans = "/"+top + ans; 
        }
        if(ans=="")return "/";
        return ans;
    }
};