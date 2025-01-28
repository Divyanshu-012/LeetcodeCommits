class Solution {
public:
    vector<vector<int>>vis;
    void bfs(vector<vector<char>>&mat, int i, int j)
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x+1<n && vis[x+1][y]==0 && mat[x+1][y]=='X')
            {
                vis[x+1][y]=1;
                q.push({x+1,y});
            }
            if(x-1>=0 && vis[x-1][y]==0 && mat[x-1][y]=='X')
            {
                vis[x-1][y]=1;
                q.push({x-1,y});
            }
            if(y+1<m && vis[x][y+1]==0 && mat[x][y+1]=='X')
            {
                vis[x][y+1]=1;
                q.push({x,y+1});
            }
            if(y-1>=0 && vis[x][y-1]==0 && mat[x][y-1]=='X')
            {
                vis[x][y-1]=1;
                q.push({x,y-1});
            }
        }
    }
    int countBattleships(vector<vector<char>>& board) 
    {
        int n = board.size();
        int m = board[0].size();
        vis.resize(n,vector<int>(m,0));
        int c = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='X' && vis[i][j]==0)
                {
                    bfs(board,i,j);
                    c++;
                }
            }
        }
        return c;
    }
};