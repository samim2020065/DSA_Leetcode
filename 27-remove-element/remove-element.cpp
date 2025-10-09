class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,right = nums.size()-1;
        while(left<=right){
        	//cout<<left<<" "<<right<<endl;
        	while(right>=0&&nums[right]==val){
                right--;
                
        	}
        	if(left<=right){
        		if(nums[left]==val){
	        		swap(nums[left],nums[right]);
	        		
	        		right--;
        	    }
        	    left++;
        	}
        	
        }
        
        // for(int i=0;i<nums.size();i++){
        // 	cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return right+1;
    }
};