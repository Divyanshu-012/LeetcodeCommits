class Solution {
public:
    bool checkValidString(string s) {
        vector<int> opening;
        vector<int> flag;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                opening.push_back(i);
            } else if (s[i] == '*') {
                flag.push_back(i);
            } else if (s[i] == ')') {
                if (!opening.empty()) {
                    opening.pop_back();
                } else if (!flag.empty()) {
                    flag.pop_back();
                } else {
                    return false;
                }
            }
        }

        while (!opening.empty() && !flag.empty()) {
            if (opening.back() > flag.back()) {
                return false;
            }
            opening.pop_back();
            flag.pop_back();
        }

        return opening.empty();
    }
};