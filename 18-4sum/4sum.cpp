class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        // for(auto it:nums){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        vector<vector<int>>ans;
        for(int i=0;i<nums.size();i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            
            while(j<nums.size()){
                
                int k=j+1,l=nums.size()-1;
                while(k<l){
                long long tar = 1LL * nums[i]+nums[j]+nums[k]+nums[l];
                if(tar>target){
                    l--;
                }
                else if(tar<target){
                    k++;
                }
                else{
                    vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l&&nums[k]==nums[k-1]){
                        k++;
                    }
                    while(k<l&&nums[l]==nums[l+1]){
                        l--;
                    }
                }
              }
              j++;
              while(j<nums.size()&&nums[j]==nums[j-1]){
                j++;
              }
              
            }
            //cout<<i<<endl;
            
        }
        return ans;
    }
};