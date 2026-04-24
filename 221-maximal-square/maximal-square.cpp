class Solution {
public:
    int func(int x,int y,vector<vector<char>>& matrix,vector<vector<int>>& dp){
        int n=matrix.size(),m=matrix[0].size();
        if(x>=n||y>=m){
            return 0;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(matrix[x][y]=='0'){
            dp[x][y]=0;
        }
        else{
            int right=func(x,y+1,matrix,dp);
            int down=func(x+1,y,matrix,dp);
            int diag=func(x+1,y+1,matrix,dp);
            dp[x][y]=1+min({right,down,diag});
        }
        return dp[x][y];

    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int res=func(i,j,matrix,dp);
                mx=max(mx,res*res);
            }
        }
        return mx;
    }
};