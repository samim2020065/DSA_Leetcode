class Solution {
public:
    bool func(int idx,string& s,unordered_set<string>&st,vector<int>&dp){
        if(idx==s.size()){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int j=idx;j<s.size();j++){
            string word=s.substr(idx,j-idx+1);
            if(st.count(word)&&func(j+1,s,st,dp)){
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size(),-1);
        return func(0,s,st,dp);
    }
};