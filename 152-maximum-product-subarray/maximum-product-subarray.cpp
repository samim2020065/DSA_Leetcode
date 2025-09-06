class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mx=INT_MIN,suff=1,pre=1;
        for(int i=0;i<nums.size();i++){
            
            pre*=nums[i];
            suff*=nums[nums.size()-1-i];
            //cout<<pre<<" "<<suff<<endl;
            mx=max(mx,max(pre,suff)); 
            if(nums[i]==0){
                pre=1;
                
            }
            
            if(nums[nums.size()-1-i]==0){
                suff=1;
                
            }
            
            
            
        }
        return mx;
    }
};