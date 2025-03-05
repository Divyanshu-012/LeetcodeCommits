class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size(); 
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(stoi(nums[i], 0, 2));
        }

        for (int i = 0; i <= n; i++) {
            if (st.find(i) == st.end()) { 
                string temp = bitset<16>(i).to_string();
                return temp.substr(16 - n, n); 
            }
        }

        return ""; 
    }
};
