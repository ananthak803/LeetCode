class Solution {
public:
    // vector<vector<int>> dp;
    // int helper(vector<vector<int>>& t,int i,int j,int m){
    //     if(dp[i][j]!=1e8)return dp[i][j];
    //     if(i==m-1)return dp[i][j]= t[i][j];
    //     int b=1e8,d=1e8;
    //     b=t[i][j]+helper(t,i+1,j,m);
    //     d=t[i][j]+helper(t,i+1,j+1,m);
    //     return dp[i][j]=min(b,d);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        // dp.resize(m,vector<int>(m,1e8));
        // return helper(triangle,0,0,m);
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int i=0;i<m;i++){
            dp[m-1][i]=triangle[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int b=1e8,d=1e8;
                b=triangle[i][j]+dp[i+1][j];
                d=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(b,d);
            }
        }
    
        return dp[0][0];

    }
};