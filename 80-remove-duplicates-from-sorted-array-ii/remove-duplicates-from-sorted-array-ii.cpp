class Solution {
public:
int removeDuplicates(vector<int>& nums) {
        int i=0,f=0;
        for(int j=1;j<nums.size();j++){
        	if(nums[j]!=nums[i]){
        		nums[++i]=nums[j];
        		f=0;
        	}
        	else{
        		if(f==0){
        			nums[++i]=nums[j];
        			f=1;
        		}
        	}
        }
        // for(int i=0;i<nums.size();i++){
        // 	cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        return ++i;
    }
};