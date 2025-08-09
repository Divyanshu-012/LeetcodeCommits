class Solution {
public:
vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        if (heights.empty()) {
            return 0;
        }
        
        int m = heights.size();
        int n = heights[0].size();
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> minHeap;
        
        
        vector<vector<int>>res(m,vector<int>(n,INT_MAX));
        res[0][0]= 0;
        minHeap.push({0,{0, 0}});

        while (!minHeap.empty()) {
            auto diff = minHeap.top().first;
           auto coord = minHeap.top().second;
           minHeap.pop();
            int x = coord.first;

            int y = coord.second;

            if(x == m-1 && y == n-1)return diff;
            

            
            for (auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                
                if (0 <= x_ && x_ < m && 0 <= y_ && y_ < n ) {
                    int absDiff = abs(heights[x_][y_] - heights[x][y]);
                     int maxDiff = max(diff, absDiff);
                    if(res[x_][y_] > maxDiff){
                        res[x_][y_] = maxDiff;
                        minHeap.push({maxDiff, {x_, y_}});
                    }
                }
            }
        }
        
        return res[m-1][n-1];        
    }
};