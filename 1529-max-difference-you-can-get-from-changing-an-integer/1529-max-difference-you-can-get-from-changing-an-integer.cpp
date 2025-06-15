class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        int n = s.size();
        char save;
        string maxi = "", mini = "";

        for (int i = 0; i < n; i++) {
            if (s[i] != '9') {
                save = s[i];
                break;
            }
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == save) {
                maxi += '9';
            } else {
                maxi += s[i];
            }
        }

        if (s[0] != '1') {
            char ch = s[0];
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    mini += '1';
                } else {
                    mini += s[i];
                }
            }
        } else {
            char ch = 0;
            for (int i = 1; i < n; i++) {
                if (s[i] != '0' && s[i] != '1') {
                    ch = s[i];
                    break;
                }
            }
            for (int i = 0; i < n; i++) {
                if (s[i] == ch) {
                    mini += '0';
                } else {
                    mini += s[i];
                }
            }
        }

        return stoi(maxi) - stoi(mini);
    }
};
