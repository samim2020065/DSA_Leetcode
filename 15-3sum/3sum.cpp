class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       map<int,int>mp;
       set<vector<int>>st;
       for(int i=0;i<nums.size()-1;i++){
        for(int j=i+1;j<nums.size();j++){
           int target = -(nums[i]+nums[j]);
           if(mp.find(target)!=mp.end()){
            vector<int>temp={nums[i],nums[j],target};
            sort(temp.begin(),temp.end());
            st.insert(temp);
           }
        }
        mp[nums[i]]++;
       } 
       vector<vector<int>>ans(st.begin(),st.end());
       return ans;
    }
};