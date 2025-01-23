class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m =  isWater.size() , n = isWater[0].size();
        // FIND 1 and shift them to 0 and if its 0 shift them to -ve

        vector<vector<int>> h(m,vector<int>(n,-1));
        queue<pair<int,int>>q;

        for(int i = 0; i< m; i++){
            for(int j = 0; j< n; j++){
                if(isWater[i][j] == 1){
                    h[i][j] = 0;
                    q.push({i,j});

                } 
            }
        }
        int drow[] = {-1,1,0,0};
        int dcol[] = {0,0,-1,1};

    while(!q.empty()){
        int s = q.size();

        for(int k = 0 ;  k< s;k++){

            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int l = 0 ; l< 4 ;  l++){
                int nrow = i+drow[l];
                int ncol = j+dcol[l];

                if(nrow < m && nrow >= 0 && ncol < n && ncol>=0 && h[nrow][ncol] == -1){
                    h[nrow][ncol ] = h[i][j] +1;
                    q.push({nrow,ncol});
                }

            }
        }

    }
        

        return h;
        
    }
};