class Solution {
public:
int func(int x,int y,string &s1,string &s2,vector<vector<int>>&dp){
	if(x==0){
		return y;
	}
	if(y==0){
		return x;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	if(s1[x-1]==s2[y-1]){
		return dp[x][y]=func(x-1,y-1,s1,s2,dp);
	}
	int del=func(x-1,y,s1,s2,dp);
	int ins=func(x,y-1,s1,s2,dp);
	int rep=func(x-1,y-1,s1,s2,dp);
	return dp[x][y]=1+min({del,ins,rep});
}
int minDistance(string word1, string word2) {
	int n=word1.size(),m=word2.size();
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return func(n,m,word1,word2,dp);
}
};