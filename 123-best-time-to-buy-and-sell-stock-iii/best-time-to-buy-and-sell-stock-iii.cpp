class Solution {
public:
int func(int x,int buy,int cap,vector<int>&prices,vector<vector<vector<int>>>&dp){
	if(x==prices.size()||cap==0){
		return 0;
	}
	if(dp[x][buy][cap]!=-1){
		return dp[x][buy][cap];
	}
	int profit;
	if(buy){
		profit=max(-prices[x]+func(x+1,0,cap,prices,dp),func(x+1,1,cap,prices,dp));
	}
	else{
		profit=max(prices[x]+func(x+1,1,cap-1,prices,dp),func(x+1,0,cap,prices,dp));
	}
	return dp[x][buy][cap]=profit;
}
int maxProfit(vector<int>& prices) {
	int n=prices.size();
	vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
	return func(0,1,2,prices,dp);
}
};