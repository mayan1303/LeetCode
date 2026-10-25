class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool valid(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    void dfs(vector<vector<int>>& grid, int i, int j,int n, int m, 
        vector<vector<bool>>& vis,bool& closed){
            vis[i][j]=true;
            if(i==0 || i==n-1 || j==0 || j==m-1){
                closed =false;
            }
            for(int k=0;k<4;k++){
                int row=i+x[k];
                int col=j+y[k];
                if(valid(row, col, n, m) && grid[row][col]==0 && vis[row][col]==0){
                    dfs(grid, row, col, n, m, vis, closed);
                }
            }
        }

    int closedIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        int res=0;
        
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vector<bool> t(m,0);
            vis[i]=t;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool closed=true;
                if(grid[i][j]==0 && vis[i][j]==0){
                    dfs(grid, i, j, n, m, vis, closed);
                    if(closed==true){
                        res++;
                    }
                }
            }
        }

        return res;
    }
};