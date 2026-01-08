class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int inf=1e9;
    int rec(int x,int y,vector<vector<int>>& g){
        if(x>=m || y>=n){
            return inf;
        }
        if(x==m-1 && y==n-1){
            return max(1,1-g[y][x]);
        }
        if(dp[y][x]!=-1){
            return dp[y][x];
        }
        int ans=max(1,min(rec(x+1,y,g),rec(x,y+1,g))-g[y][x]);
        return dp[y][x]=ans;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        n=dungeon.size();
        m=dungeon[0].size();
        dp.assign(n,vector<int>(m,-1));
        return rec(0,0,dungeon);
    }
};