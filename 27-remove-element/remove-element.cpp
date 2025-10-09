class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left=0,right = nums.size()-1;
        while(left<right){
        	//cout<<left<<" "<<right<<endl;
        	while(right>=0&&nums[right]==val){
                right--;
                
        	}
        	if(left<right){
        		if(nums[left]==val){
	        		swap(nums[left],nums[right]);
	        		left++;
	        		right--;
        	    }
        	    else{
        			left++;
        	    }
        	}
        	
        }
        int x=nums.size();
        for(int i=0;i<nums.size();i++){
        	if(nums[i]==val){
        		x=i;
        		break;
        	}
        }
        // for(int i=0;i<nums.size();i++){
        // 	cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return x;
    }
};