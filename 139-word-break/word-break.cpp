class Solution {
public:
bool func(int ind,string &s,unordered_set<string>&wordDict,vector<int>&dp){
	if(ind==s.size()){
		return true;
	}
	if(dp[ind]!=-1){
		return dp[ind];
	}
	for(int j=ind+1;j<=s.size();j++){
		if(wordDict.count(s.substr(ind,j-ind))&&func(j,s,wordDict,dp)){
			return dp[ind]=1;
		}
	}
	return dp[ind]=0;
}
bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string>dict(wordDict.begin(),wordDict.end());
	int n=s.size();
	vector<int>dp(n,-1);
	return func(0,s,dict,dp);
}
};