class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xor_cnt=0;
        for(int i=0;i<nums.size();i++){
             xor_cnt^=nums[i];
        }
        return xor_cnt;
    }
};