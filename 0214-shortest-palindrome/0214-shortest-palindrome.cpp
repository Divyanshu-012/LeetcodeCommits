class Solution {
public:
    // Function to compute the Longest Prefix-Suffix (LPS) array
    vector<int> LPS(string pat) {
        int n = pat.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;

        while (i < n) {
            if (pat[i] == pat[j]) {
                lps[i++] = ++j;
            } else {
                if (j == 0) {
                    lps[i++] = 0;
                } else {
                    j = lps[j - 1];
                }
            }
        }
        return lps;
    }

    // Function to find the shortest palindrome by adding characters to the front
    string shortestPalindrome(string s) {
        if (s.empty()) return "";

        // Reverse the string and create a new pattern
        string revs = s;
        reverse(revs.begin(), revs.end());
        string combined = s + "#" + revs;

        // Get the LPS array of the combined string
        vector<int> lps = LPS(combined);

        // Find the characters to add in front and create the result
        int len = lps.back();  // Length of the longest palindromic prefix
        string to_add = s.substr(len);  // Non-palindromic part
        reverse(to_add.begin(), to_add.end());

        return to_add + s;  // Add reversed non-palindromic part to the front
    }
};