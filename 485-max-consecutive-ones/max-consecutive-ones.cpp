class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,mx_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                cnt++;
                mx_cnt=max(cnt,mx_cnt);
            }
            else{
                cnt=0;
            }
        }
        return mx_cnt;
    }
};