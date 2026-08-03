class Solution {
public:
// vector<vector<int>> dp;
// int helper(int i,int j,vector<vector<int>>& g){
//     if(i<0 || j<0) return 1e8;
//     if(dp[i][j]!=-1)return dp[i][j];
//     if(i==0 && j==0) return g[i][j];
//     int l=1e8,u=1e8;
//     l=g[i][j]+helper(i,j-1,g);
//     u=g[i][j]+ helper(i-1,j,g);
//     return dp[i][j]=min(l,u);
// }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // dp.resize(m,vector<int>(n,-1));
        // return helper(m-1,n-1,grid);

        vector<vector<int>> dp(m,vector<int>(n,1e8));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int u=1e8,l=1e8;
                if(i==0 && j==0)continue;
                if(j>0)l=grid[i][j] + dp[i][j-1];
                if(i>0)u=grid[i][j]+ dp[i-1][j];
                dp[i][j]=min(l,u);
            }
        }
        return dp[m-1][n-1];
    }
};