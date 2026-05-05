class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mp;
        int mxLen=0,prev=-1;
        for(int i=0;i<n;i++){
            if(mp.find(s[i])!=mp.end()){
                prev=max(prev,mp[s[i]]);
            }
            mxLen=max(mxLen,i-prev);
            mp[s[i]]=i;
        }
        return mxLen;
    }
};