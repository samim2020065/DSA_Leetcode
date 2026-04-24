class Solution {
public:
    int func(int x,int y,string&word1,string &word2,vector<vector<int>>&dp){
        if(x<0){
            return y+1;
        }
        if(y<0){
            return x+1;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        if(word1[x]==word2[y]){
            dp[x][y]=func(x-1,y-1,word1,word2,dp);
        }
        else{
            int del=func(x-1,y,word1,word2,dp);
            int ins=func(x,y-1,word1,word2,dp);
            int rep=func(x-1,y-1,word1,word2,dp);
            dp[x][y]=1+min({del,ins,rep});
        }
        return dp[x][y];
    }
    int minDistance(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return func(n-1,m-1,word1,word2,dp);
    }
};