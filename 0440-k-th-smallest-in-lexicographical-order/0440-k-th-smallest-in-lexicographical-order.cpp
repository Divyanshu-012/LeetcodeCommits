class Solution {
public:
    int Count(long curr, long next, int n) {
        int cnt = 0;
        while (curr <= n) {
            cnt += min((long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--; // we consider 1 as already included

        while (k > 0) {
            int cnt = Count(curr, curr + 1, n);
            if (cnt <= k) {
                curr += 1;
                k -= cnt;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};
