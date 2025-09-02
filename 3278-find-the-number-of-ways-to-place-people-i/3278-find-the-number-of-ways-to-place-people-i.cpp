class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                int r1 = points[i][0]; int c1 = points[i][1];
                int r2 = points[j][0]; int c2 = points[j][1];
                if (r1 >= r2 && c1 <= c2) {}
                else if (r1 <= r2 && c1 >= c2) {
                    swap(r1, r2);
                    swap(c1, c2);
                }
                else {continue;}
                bool can = true;
                for (int k=0; k<n; k++) {
                    if (i != k && j != k) {
                        int r3 = points[k][0]; int c3 = points[k][1];
                        if (r3 <= r1 && r3 >= r2 && c3 >= c1 && c3 <= c2) {
                            can = false;
                        }
                    }
                }
                if (can) {++ans;}
            }
        }
        return ans;
    }
};