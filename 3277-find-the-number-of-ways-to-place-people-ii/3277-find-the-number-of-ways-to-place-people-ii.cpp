class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto& a, auto& b) {
            if (a[0] != b[0])
                return a[0] < b[0];
            return a[1] > b[1];
        });
        int n = points.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            int maxY=INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                if (y2 <= y1) {
                    if(maxY<y2)
                       res++;
                    maxY=max(maxY, y2);   
                }
            }
        }
        return res;
    }
};