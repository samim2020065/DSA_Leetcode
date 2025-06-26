class Solution {
public:
    bool check(vector<int>& nums) {
	int mn=nums[0];
	int flag=0;
	for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1]){
        	if(flag==0){
        		flag=1;
        	}
        	else{
        		flag=2;
        	}
        }
	}
	if(flag==2){
		return false;
	}
	else if(flag==0){
		return true;
	}
	else{
		if(nums[nums.size()-1]<=nums[0]){
			return true;
		}
		else{
			return false;
		}
	}
        
}
};