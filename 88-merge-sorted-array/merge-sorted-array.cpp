class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=0;
        while(i>=0&&j<n){
            if(nums1[i]>nums2[j]){
               swap(nums1[i],nums2[j]);
               i--;
               j++;
            }
            else{
                break;
            }
            
        }
        // for(auto it:nums1){
        //     cout<<it<<" ";
        // }
        sort(nums1.begin(),nums1.begin()+m);
        sort(nums2.begin(),nums2.end());
        int x=0;
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[x];
            x++;
        }
        // for(auto it:nums1){
        //     cout<<it<<" ";
        // }

    }
};