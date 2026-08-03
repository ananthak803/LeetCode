class Solution {
public:
// vector<vector<int>> dp;
    // int helper(int i,int j){
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1)return dp[i][j];
    //     if(i==0 && j==0)    return 1;
    //     int l=helper(i,j-1);
    //     int u=helper(i-1,j);
    //     return dp[i][j]=l+u;
    // }
    int uniquePaths(int m, int n) {
        // dp.resize(m,vector<int>(n,-1));
        // return helper(m-1,n-1);

        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0)continue;
                int l=0,u=0;
                if(j>0) l=dp[i][j-1];
                if(i>0) u=dp[i-1][j];
                dp[i][j]=l+u;
            }
        }
        return dp[m-1][n-1];

    }
};