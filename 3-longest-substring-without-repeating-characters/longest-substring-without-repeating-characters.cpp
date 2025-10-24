class Solution {
public:
int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0,right=0,ans=0;
        unordered_set<int>st;
        for(int i=right;i<n;i++){
            if(st.find(s[i])!=st.end()){
                while(st.find(s[i])!=st.end()){
                    
                    st.erase(s[left]);
                    left++;
                }
            }
            st.insert(s[i]);
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};