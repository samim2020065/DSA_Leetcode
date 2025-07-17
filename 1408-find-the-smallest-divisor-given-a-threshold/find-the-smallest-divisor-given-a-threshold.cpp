class Solution {
public:
    bool check(int mid,vector<int>&a,int h){
    long long sum=0;
    for(int i=0;i<a.size();i++){
        sum+=(a[i]+mid-1)/mid;
    }
    if(sum<=h){
        return true;
    }
    return false;
}
int smallestDivisor(vector<int>& nums, int threshold) {
        int mx;
        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
        }
        int low=1;int high=mx;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,nums,threshold)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};