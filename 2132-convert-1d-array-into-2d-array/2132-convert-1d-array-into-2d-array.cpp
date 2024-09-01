class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // vector<vector<int>> array2D;
        
        if (m * n != original.size()) {
            return {};  // Return an empty vector if the dimensions don't match
        }

        vector<vector<int>> arr2D(m, vector<int>(n));
        for (int i = 0; i < m * n; i++) {
            arr2D[i / n][i % n] = original[i];
        }

        return arr2D;
        
    }
};