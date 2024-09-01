class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>> arr2D(m, vector<int>(n));
        if (m * n != original.size()) {
            return {};  
        }

        for (int i = 0; i < m; i++) {        
            for (int j = 0; j < n; j++) {    
                
                arr2D[i][j] = original[i * n + j];
            }
        }

        return arr2D;
        
    }
};