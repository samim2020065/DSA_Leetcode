class Solution {
public:
int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int curmin=0,globalmin=nums[0],curmax=0,globalmax=nums[0],totalsum=0;
        for(int i=0;i<n;i++){
            totalsum+=nums[i];
            curmax=max(curmax+nums[i],nums[i]);
            globalmax=max(globalmax,curmax);
            curmin=min(curmin+nums[i],nums[i]);
            globalmin=min(globalmin,curmin);
        }
        if(globalmax<0){
            return globalmax;
        }
        return max(globalmax,totalsum-globalmin);
    }
};