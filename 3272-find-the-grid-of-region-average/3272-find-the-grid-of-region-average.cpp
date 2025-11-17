class Solution {
public:
    vector<vector<int>> pre_sum;
    int rows;
    int cols;
    vector<vector<int>> resultGrid(vector<vector<int>>& image, int t) {
        rows = image.size();
        cols = image[0].size();

        vector<vector<pair<double, int> >> v(rows, vector<pair<double, int>>(cols));
        vector<vector<int>> res(rows, vector<int>(cols));

        pre_sum = vector<vector<int>> (rows+1, vector<int> (cols+1,0));

        calculate_pre_sum(image);
       
       for(int i=0; i< rows-2; ++i) {
            for (int j=0; j<cols-2; ++j) {
                int temp_sum =0;
                bool region = true;

                for(int pp = i; pp<i+3; ++pp) {
                    int qq =j;
                    for(; qq<j+3; ++qq) {
                        /* 
                        To detect a region, we compare each node with its right and bottom neighbors. For example, if we are detecting a region with the top-left corner at (i=2, j=4), when checking the neighbors of (i=3, j=5), we only compare it with (i=4, j=5) and (i=3, j=6). The left and top neighbors have already been checked in previous comparisons.
                        */
                        if ( (pp <i+2) && (abs(image[pp][qq] - image[pp+1][qq]) > t ) ||
                             (qq <j+2) && (abs(image[pp][qq] - image[pp][qq+1]) >t)
                            ) { 
                                region = false;
                                break; 
                        }

                    }
                    if (!region) {
                        
                        break;
                    }
                }

                if(region) {
                    /* If a region is detected, update the sum and frequency for all the nodes within that region. I initially considered optimizing this by only tracking the top-left corner indices of the region, but then realized that the number of regions a node can belong to may vary, so this approach wouldn't work consistently.
                    */
                    temp_sum = calculate_sum_from_to(i, j, i+2, j+2);
                    for (int k = i; k < i + 3 && k < rows; k++) {
                            for (int l = j; l < j + 3 && l < cols; l++) {
                                v[k][l].first += temp_sum / 9;
                                v[k][l].second++;
                            }
                    }
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = v[i][j].second == 0 ? image[i][j] : v[i][j].first / v[i][j].second;
                }
        }
        return res;
    }

    void calculate_pre_sum(vector<vector<int>>& image) {
        for(int i=1; i<=rows; ++i) {
            for(int j=1; j<=cols ; ++j) {
                pre_sum[i][j] = image [i-1][j-1] //note pre_sum size is larger
                                + pre_sum[i-1][j] +  pre_sum[i][j-1] - pre_sum[i-1][j-1];

            }
        }
    }

    int calculate_sum_from_to (int row1, int col1, int row2, int col2) {
        return pre_sum[row2+1][col2+1] - pre_sum[row2+1][col1] - pre_sum[row1][col2+1] + pre_sum[row1][col1];
    }


    void print(vector<vector<int>> &m) {
        for(auto e: m) {
            for (auto ee: e) {
                cout<<ee<<" ";
            }
            cout<<endl;
        }
    }
};