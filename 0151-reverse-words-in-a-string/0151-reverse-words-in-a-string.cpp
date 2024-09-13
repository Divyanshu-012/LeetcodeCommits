class Solution {
public:
    string reverseWords(string s) {
       stack<string> st;
        string str = "";
        
        // Traverse the string and split words
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!str.empty()) { // If the current word is not empty, push it to the stack
                    st.push(str);
                    str = ""; // Reset the current word
                }
            } else {
                str += s[i]; // Keep building the word
            }
        }

        // Push the last word if it exists
        if (!str.empty()) {
            st.push(str);
        }

        // Construct the reversed string
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " "; // Add a space between words
            }
        }

        return ans;
    }
};