class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int mx_len=0;
        for(auto it:st){
            int x=it,cnt=0;
            if(st.find(x-1)==st.end()){
                cnt=1;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cnt++;
                }
                mx_len=max(mx_len,cnt);
            }
        }
        return mx_len;
    }
};