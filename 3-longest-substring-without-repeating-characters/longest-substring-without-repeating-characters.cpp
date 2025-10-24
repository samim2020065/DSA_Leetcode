class Solution {
public:
int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0,right=0;
        vector<int>mp(256,-1);
        int len=0;
        for(int i=right;i<n;i++){
            if(mp[s[i]]!=-1){
                left=max(mp[s[i]]+1,left);
            }
            mp[s[i]]=i;
            len=max(len,i-left+1);
        }
        return len;
    }
};