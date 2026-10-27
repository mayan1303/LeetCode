class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<string>> grid(m,vector<string>(n,"#"));
        vector<string> ans(m);

        

        for(int i=0;i<n;i++){
            grid[0][i]=".";
        }
        for(int j=0;j<m;j++){
            grid[j][n-1]=".";
        }
        
        for(int i=0;i<m;i++){
            for(int k=0;k<n;k++){
                ans[i]+=grid[i][k];
            }
        }
        return ans;

    }
};