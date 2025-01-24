class Solution {
public:
    int trapRainWater(vector<vector<int>>& hmap) {
        int n =  hmap.size();
        int m = hmap[0].size();

        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>pq;

        vector<vector<bool>>vis(n,vector<bool>(m,false));


        for(int i = 0; i< n ;i++){
            for(int j = 0 ; j< m;j++){
                if(i == 0 || j ==0 || i == n-1 || j == m-1){
                    pq.push({hmap[i][j],{i,j}});
                    vis[i][j] = true;

                    
                }
            }
        }

        int water = 0;
        int deli[] = {0,0,-1,1};
        int delj[] = {-1,1,0,0};
        while(!pq.empty()){
            int h = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(int k = 0; k< 4 ;k++){
                int i_ = i + deli[k];
                int j_ = j + delj[k];

                if(i_ < n && i_ > 0 && j_ < m && j_ > 0 && !vis[i_][j_]){
                    water += max(h - hmap[i_][j_],0);

                    pq.push({max(h,hmap[i_][j_]),{i_,j_}});
                    vis[i_][j_] = true;

                }
            }

        }
        return water;
        
    }
};