class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size());
        int product=1;
        for(int i=nums.size()-1;i>=0;i--){
            ans[i]=product*nums[i];
            product*=nums[i];
        }
        product=1;
        for(int i=0;i<nums.size()-1;i++){
            ans[i]=product*ans[i+1];
            product*=nums[i];
        }
        ans[nums.size()-1]=product;
        return ans;
    }
};