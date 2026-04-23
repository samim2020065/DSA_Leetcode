class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans=-1;
        for(int i=0;i<haystack.size();i++){
            if(haystack[i]==needle[0]){
                int j=0;
                for(j=i;j<i+needle.size();j++){
                    if(haystack[j]!=needle[j-i]){
                        break;
                    }
                }
                if(j==i+needle.size()){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
};