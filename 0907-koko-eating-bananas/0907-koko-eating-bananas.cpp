class Solution {
public:

    int findMax(const vector<int>& piles) {
        int maxi = INT_MIN;
        for (int i = 0; i < piles.size(); i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHours(const vector<int>& piles, int hourly) {
        long long totalH = 0;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalH += ceil((double)piles[i] / (double)hourly);  // Integer ceiling division
        }
        return totalH;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = findMax(piles);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
