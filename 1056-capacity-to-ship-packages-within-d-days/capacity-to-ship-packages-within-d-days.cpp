class Solution {
public:
    bool check(int mid,vector<int>&a,int k){
    int s=0,ans=0;
    for(int i=0;i<a.size();i++){
        s+=a[i];
        if(s>mid){
            ans++;
            s=a[i];
        }
    }
    if(s>0){
        ans++;
    }
    if(ans<=k){
        return true;
    }
    else{
        return false;
    }
}
int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,mx=0;
        for(int i=0;i<weights.size();i++){
            mx=max(mx,weights[i]);
            sum+=weights[i];
        }
        int low=mx,high=sum;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(mid,weights,days)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};