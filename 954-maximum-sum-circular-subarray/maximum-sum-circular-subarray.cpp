class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMax=0,maxSum=INT_MIN;
        int currMin=0,minSum=INT_MAX;
        int total=0;
        for(auto it:nums){
            currMax=max(currMax+it,it);
            maxSum=max(maxSum,currMax);
            currMin=min(it,currMin+it);
            minSum=min(minSum,currMin);
            total+=it;
        }
        if(maxSum<0){
            return maxSum;
        }
        return max(maxSum,total-minSum);
    }
};