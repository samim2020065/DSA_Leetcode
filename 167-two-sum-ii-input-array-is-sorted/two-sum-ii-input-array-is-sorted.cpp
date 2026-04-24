class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<numbers.size();i++){
            int left=target-numbers[i];
            if(mp.find(left)!=mp.end()){
                ans.push_back(mp[left]);
                ans.push_back(i+1);
            }
            mp[numbers[i]]=i+1;
        }
        return ans;
    }
};