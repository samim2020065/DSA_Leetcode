class Solution {
public:
int func(int x,int y,int n,int m,vector<vector<char>>&matrix,vector<vector<int>>&dp){
	if(x>=n||y>=m){
		return 0;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	int right=func(x,y+1,n,m,matrix,dp);
	int down=func(x+1,y,n,m,matrix,dp);
	int diag=func(x+1,y+1,n,m,matrix,dp);
	if(matrix[x][y]=='1'){
		dp[x][y]=1+min({right,down,diag});
	}
	else{
		dp[x][y]=0;
	}
	return dp[x][y];
}
int maximalSquare(vector<vector<char>>& matrix) {
	int n=matrix.size(),m=matrix[0].size();
	vector<vector<int>>dp(n,vector<int>(m,-1));
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans=max(ans,func(i,j,n,m,matrix,dp));
		}
	}
	return ans*ans;
}
};