class Solution {
public:
int solve(int ind,int target,vector<vector<int>>&dp,vector<int>&nums){
	if(ind==0){
		if(target==0&&nums[0]==0){
			return 2;
		}
		if(target==0||nums[0]==target){
			return 1;
		}
		return 0;
	}
	if(target<0){
		return 0;
	}
	if(dp[ind][target]!=-1){
		return dp[ind][target];
	}
	int notPick=solve(ind-1,target,dp,nums);
	int pick=0;
	if(target>=nums[ind]){
		pick=solve(ind-1,target-nums[ind],dp,nums);
	}
	return dp[ind][target]=pick+notPick;
}
int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        if(target>sum||((sum-target)&1)){
        	return 0;
        }
        target=(sum-target)/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return solve(n-1,target,dp,nums);
    }
};