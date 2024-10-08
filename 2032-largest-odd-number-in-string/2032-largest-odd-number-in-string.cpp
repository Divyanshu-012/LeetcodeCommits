class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();
        int i = n - 1;

        while (i >= 0) {  
            if (num[i] % 2 == 0) {
                i--;
            } else {
                return num.substr(0, i + 1); 
            }
        }

        return "";
    }
};
