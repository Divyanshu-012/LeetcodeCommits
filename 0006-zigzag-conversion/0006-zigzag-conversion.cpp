class Solution {
public:
    string convert(string s, int r) {
        if (r == 1 || s.size() <= r) return s;

        vector<string> rows(r);
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c;
            if (curRow == 0 || curRow == r - 1) goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string ans;
        for (string row : rows) ans += row;
        return ans;
    }
};
