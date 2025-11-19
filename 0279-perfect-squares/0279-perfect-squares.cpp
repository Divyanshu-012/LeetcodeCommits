class Solution {
public:
    int numSquares(int n) {
        int maxIndex = sqrt(n);

        vector<int> result(n+1, 1e5);

        result[0] = 0;
        
        for(int i = 1; i <= maxIndex; i++) {
            for(int j = 1; j <= n; j++) {
                int num = i * i;

                if(num <= j)
                    result[j] = min(1 + result[j-num], result[j]);
            }
        }

        return result[n];
    }
};