class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>pre_sum;
        int sum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum==k){
                cnt++;
            }
            int rem=sum-k;
            if(pre_sum.find(rem)!=pre_sum.end()){
                cnt+=pre_sum[rem];
            }
            pre_sum[sum]++;
        }
        return cnt;
    }
};