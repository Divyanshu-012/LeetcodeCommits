class Solution {
public:
    
        
    string smallestNumber(string p) {
        int n = p.length();
        string num = "";

        int cnt = 1;

        stack<char> st;

        for(int i = 0; i<= n; i++){
            st.push(cnt + '0');
            cnt++;

            if(i == n || p[i] == 'I'){
                while(!st.empty()){
                    num+= st.top();
                    st.pop();

                }
            }
        }

       

        return num;
    }
};