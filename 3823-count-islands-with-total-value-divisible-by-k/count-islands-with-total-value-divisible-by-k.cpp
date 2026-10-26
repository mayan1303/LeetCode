class Solution {
public:
    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};

    bool valid(int n, int m, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    long long dfs(vector<vector<int>>& grid, int n, int m, int i, int j, vector<vector<bool>>& vis){
        vis[i][j]=true;
        long long sum=grid[i][j];

        for(int k=0;k<4;k++){
            int row=i+x[k];
            int col=j+y[k];
            if(valid(n,m,row,col) && grid[row][col]>0 && vis[row][col]==false){
                sum+=dfs(grid , n, m, row, col, vis);
            }
        }
        return sum;
    }




    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        long long sum;
        int res=0;
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            vis[i]=t;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum=0;
                if(grid[i][j]>0 && vis[i][j]==false){
                sum=dfs(grid , n, m, i, j, vis);
                if(sum%k == 0) res++;
            }
            }
        }
        return res;
    }

};