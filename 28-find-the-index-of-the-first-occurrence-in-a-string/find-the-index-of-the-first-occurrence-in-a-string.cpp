class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        int f=0;
        for(int i=0;i<=n-m;i++){
            for(int j=0;j<m;j++){
                
                if(needle[j]!=haystack[i+j]){
                    f=1;
                    break;
                }
            }
            if(f==0){
                return i;
            }
            f=0;
        }
        return -1;
    }
};