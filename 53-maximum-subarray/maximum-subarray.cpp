class Solution {
public:
    
    int maxSubArray(vector<int>& nums) {
        int sum=0,mx_sum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mx_sum=max(mx_sum,sum);
            if(sum<0){
                sum=0;
            }
        }
        return mx_sum;
    }
};