class Solution {
public:
    int func(int idx,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(idx==0){
            if(amount%coins[idx]==0){
                return amount/coins[idx];
            }
            else{
                return 1e9;
            }
        }
        if(dp[amount][idx]!=-1){
            return dp[amount][idx];
        }
        int notTake=func(idx-1,amount,coins,dp);
        int take=1e9;
        if(amount>=coins[idx]){
            take=1+func(idx,amount-coins[idx],coins,dp);
        }
        return dp[amount][idx]=min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n,-1));
        int res=func(n-1,amount,coins,dp);
        if(res>=1e9){
            return -1;
        }
        return res;
    }
};