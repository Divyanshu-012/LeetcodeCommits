class Solution {
public:
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }

    int calculate(string s) {
        stack<int> st;
        long long curr_num = 0;
        char sign = '+';

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isDigit(c)) {
                curr_num = curr_num * 10 + (c - '0');
            }

            if ((!isDigit(c) && c != ' ') || i == s.size() - 1) {
                if (sign == '+') {
                    st.push(curr_num);
                } else if (sign == '-') {
                    st.push(-curr_num);
                } else if (sign == '*') {
                    int tp = st.top(); st.pop();
                    st.push(tp * curr_num);
                } else if (sign == '/') {
                    int tp = st.top(); st.pop();
                    st.push(tp / curr_num);
                }
                sign = c;
                curr_num = 0;
            }
        }

        int total_value = 0;
        while (!st.empty()) {
            total_value += st.top();
            st.pop();
        }
        return total_value;
    }
};