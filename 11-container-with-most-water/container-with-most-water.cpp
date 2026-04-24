class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0,right=height.size()-1;
        int mx=0;
        while(left<right){
            mx=max(mx,min(height[left],height[right])*(right-left));
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return mx;
    }
};