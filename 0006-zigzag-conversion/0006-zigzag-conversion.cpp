class Solution {
public:
    string convert(string s, int r) {
        if (r == 1) return s; // No zigzag pattern needed

        int n = s.size();
        string ans;
        int d = 2 * r - 2;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j + i < n; j += d) {
                
                ans += s[j + i];

                
                if (i != 0 && i != r - 1 && j + d - i < n) {
                    ans += s[j + d - i];
                }
            }
        }

        return ans;
    }
};