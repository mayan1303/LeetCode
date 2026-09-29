class Solution {
public:
    bool valid(int i, int j,int m, int n){
                if(i<0 || i>=m || j<0 || j>=n) return false;
                return true;
            }

    
    bool solve(vector<vector<char>>& grid, int i, int j, int balance, vector<vector<vector<int>>>& dp){
        int m=grid.size();
        int n=grid[0].size();
        balance+=(grid[i][j]=='(')?1:-1;
if(balance<0)return false;
        
        if(dp[i][j][balance]!=-1) return dp[i][j][balance];
        if(i==m-1 && j==n-1){
            return (balance==0);
        }
        if(i+1<m){
            if(solve(grid,i+1,j,balance,dp)){
                return dp[i][j][balance]=true;
            }
        }
        if(j+1<n){
            if(solve(grid,i,j+1,balance,dp)){
                return dp[i][j][balance]=true;
            }
        }
        
            
        return dp[i][j][balance]=false;
        

    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(m+n,-1)));


        if(grid[0][0]==')' || grid[m-1][n-1]=='('){
            return false;
        }
        return solve(grid,0,0,0,dp);
        

             
    }
};