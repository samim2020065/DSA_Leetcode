class Solution {
public:
int solve(int x,int y,vector<vector<int>>&grid,vector<vector<int>>&dp){
	if(x<0||y<0){
		return INT_MAX;
	}
	if(x==0&&y==0){
		return grid[0][0];
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	int left=solve(x,y-1,grid,dp);
	int up=solve(x-1,y,grid,dp);
	int bestleft=(left==INT_MAX?INT_MAX:left+grid[x][y]);
	int bestup=(up==INT_MAX?INT_MAX:up+grid[x][y]);
	return dp[x][y]=min(bestleft,bestup);
}
int minPathSum(vector<vector<int>>& grid) {
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	return solve(n-1,m-1,grid,dp);
        
    }
};