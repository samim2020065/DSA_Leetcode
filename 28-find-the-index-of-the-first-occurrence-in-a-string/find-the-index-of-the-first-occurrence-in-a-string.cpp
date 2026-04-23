class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size()<needle.size()){
            return -1;
        }
        int ans=-1;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            if(haystack[i]==needle[0]){
                bool match=true;
                for(int j=i;j<i+needle.size();j++){
                    if(haystack[j]!=needle[j-i]){
                        match=false;
                    }
                }
                if(match==true){
                    ans=i;
                    break;
                }
            }
        }
        return ans;
    }
};