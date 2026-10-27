class Solution {
public:
    
    bool valid(int i, int j, int m, int n){
        if(i<0 || i>=m || j<0 || j>=n) return false;
        return true;
    }

    void dfs(vector<vector<int>>& grid, int m, int n, int i, int j, int& peri, vector<vector<bool>>& vis){
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        vis[i][j]=true;


        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];

            if(!valid(row,col,m,n)) peri++;
            else if(grid[row][col]==0) peri++;
            else if(grid[row][col]==1 && !vis[row][col]){
                dfs(grid, m, n, row, col, peri, vis);
            }

        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<bool>> vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    dfs(grid, m,n,i,j,peri,vis);
                    return peri;
                }
            }
        }
        
        return 0;

       
    }
};