class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // Convert the integers to strings
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }

        // Custom sort comparator
        sort(strNums.begin(), strNums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // If the largest number is '0', then the entire number is '0'
        if (strNums[0] == "0") return "0";

        // Concatenate the sorted strings
        string largestNum = "";
        for (string s : strNums) {
            largestNum += s;
        }

        return largestNum;
    }
};
