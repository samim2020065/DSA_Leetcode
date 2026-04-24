class Solution {
public:
    int func(int left,int right,string& s){
        int mx=0;
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            mx=max(mx,right-left+1);
            left--;
            right++;
        }
        return mx;
    }
    string longestPalindrome(string s) {
        int mxLen=0,start;
        for(int i=0;i<s.size();i++){
            int len1=func(i,i,s);
            int len2=func(i,i+1,s);
            int len=max(len1,len2);
            if(len>mxLen){
                mxLen=len;
                start=i-(mxLen-1)/2;
            }
        }
        return s.substr(start,mxLen);
    }
};