class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int hMax= 0;
        int wMax = 0;
        
        int n = grid.size();
        int m = grid[0].size();
        int rLeast = n;
        int rMax = 1;
        int cLeast = m;
        int cMax = 1;
        int cnt = 0;

        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == 1){
                    cnt++;
                    if(i+1 < rLeast) rLeast = i+1;
                    if(i+1 > rMax) rMax = i+1;
                    if(j+1 < cLeast) cLeast = j+1;
                    if(j+1 > cMax) cMax = j+1;
                }
            }
        }
        if(cnt == 1) return 1;
        if((rLeast == rMax)) return (cMax - cLeast +1);
        if((cLeast == cMax)) return (rMax - rLeast +1);

        wMax = cMax - cLeast+1;
        hMax = rMax - rLeast+1;
        return wMax*hMax;
    }
};