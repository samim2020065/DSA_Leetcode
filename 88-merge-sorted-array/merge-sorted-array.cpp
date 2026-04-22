class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums(m,0);
        for(int i=0;i<m;i++){
            nums[i]=nums1[i];
        }
        int i=0,j=0,x=0;
        while(i<m&&j<n){
            if(nums[i]>nums2[j]){
                nums1[x]=nums2[j];
                j++;
            }
            else{
                nums1[x]=nums[i];
                i++;
            }
            x++;
        }
        while(i<m){
            nums1[x]=nums[i];
            i++;
            x++;
        }
        while(j<n){
            nums1[x]=nums2[j];
            j++;
            x++;
        }
    }
};