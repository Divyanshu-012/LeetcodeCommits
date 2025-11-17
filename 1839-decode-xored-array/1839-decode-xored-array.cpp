class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        encoded.insert(encoded.begin(), first);
        partial_sum(encoded.begin(), encoded.end(), encoded.begin(), bit_xor<int>());
        return encoded;
    }
};