class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto it:strs){
            vector<int>cnt(26,0);
            for(char c:it){
                cnt[c-'a']++;
            }
            string key="";
            for(auto x:cnt){
                key+=to_string(x)+"#";
            }
            mp[key].push_back(it);
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
        
    }

};