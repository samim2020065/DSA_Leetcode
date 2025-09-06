class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=0;
        for(int i=m;i<n+m;i++){
            nums1[i]=nums2[x];
            x++;
        }
        // for(auto it:nums1){
        //     cout<<it<<" ";
        // }
        int gap = (n+m)/2+(n+m)%2;
        while(gap>0){
            int left=0,right=gap;
            while(right<(n+m)){
                if(nums1[left]>nums1[right]){
                    swap(nums1[left],nums1[right]);
                }
                left++;
                right++;
            }
            if(gap!=1){
                gap=(gap/2)+(gap%2);
            }
            else{
                gap=(gap/2);
            }
            
        }
        // for(auto it:nums1){
        //     cout<<it<<" ";
        // }
    }
};