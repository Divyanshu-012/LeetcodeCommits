class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        vector<bool> toRemove(s.size(), false);

        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                if (!stk.empty() && s[stk.top()] == '(') {
                    stk.pop();
                } else {
                    toRemove[i] = true;
                }
            }
        }

        // Mark remaining unmatched '(' as invalid
        while (!stk.empty()) {
            toRemove[stk.top()] = true;
            stk.pop();
        }

        // Build the result string by skipping invalid parentheses
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (!toRemove[i]) {
                result += s[i];
            }
        }

        return result;
    }
};