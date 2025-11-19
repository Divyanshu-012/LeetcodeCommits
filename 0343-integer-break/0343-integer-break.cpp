class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        int output = 0;
        for (int d = 2; d < std::min(n, 10); ++d) {
            int acc = 1, n_ = n;
            while (n_) {
                acc *= std::min(d, n_);
                n_ -= std::min(d, n_);
                output = std::max(output, acc * n_);
            }
            output = std::max(output, acc);
        }
        return output;
    }
};