class Solution {
public:
bool func(int x,int y,string &s1,string &s2,string &s3,vector<vector<int>>&dp){
	if(x==s1.size()&&y==s2.size()){
		return true;
	}
	if(dp[x][y]!=-1){
		return dp[x][y];
	}
	int k=x+y;
	bool ans=false;
	if(x<s1.size()&&s1[x]==s3[k]){
		ans|=func(x+1,y,s1,s2,s3,dp);
	}
	if(y<s2.size()&&s2[y]==s3[k]){
		ans|=func(x,y+1,s1,s2,s3,dp);
	}
	return dp[x][y]=ans;
}
bool isInterleave(string s1, string s2, string s3) {
	int n=s1.size(),m=s2.size();
	if(n+m!=s3.size()){
		return false;
	}
	vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	return func(0,0,s1,s2,s3,dp);
}
};