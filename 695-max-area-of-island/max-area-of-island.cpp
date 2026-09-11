class Solution {
public:

    int x[4]={-1,1,0,0};
    int y[4]={0,0,-1,1};
    bool isVal(int i, int j, int n, int m){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }

    int dfs(vector<vector<int>>&a,int n, int m, int i, int j,vector<vector<bool>>&vis){
        vis[i][j]=1;
        int area=1;
        for(int k=0;k<4;k++){
            int r=i+x[k];
            int c=j+y[k];
            if(isVal(r,c,n,m) && a[r][c]==1 && vis[r][c]==0){
                area+=dfs(a,n,m,r,c,vis);
                
            }
        }
        return area;
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        int area;
        vector<vector<bool>>vis(n);
        for(int i=0;i<n;i++){
            vector<bool>t(m,0);
            vis[i]=t;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    area=dfs(grid,n,m,i,j,vis);
                    ans=max(ans,area);
                }
            }
        }

        return ans;
    }
};