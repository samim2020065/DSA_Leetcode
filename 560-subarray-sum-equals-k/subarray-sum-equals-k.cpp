class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>pre_sum;
        int sum=0,cnt=0;
        pre_sum[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int remove = sum-k;
            cnt+=pre_sum[remove];
            pre_sum[sum]+=1;
            
        }
        return cnt;
    }
};