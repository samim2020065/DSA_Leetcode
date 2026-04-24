class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size()){
            return false;
        }
        int n=s1.size(),m=s2.size();
        vector<bool>dp(m+1,false);
        dp[0]=true;
        for(int i=1;i<=m;i++){
            dp[i]=dp[i-1]&&(s2[i-1]==s3[i-1]);
        }
        for(int i=1;i<=n;i++){
            dp[0]=dp[0]&&(s1[i-1]==s3[i-1]);
            for(int j=1;j<=m;j++){
                int k=i+j-1;
                dp[j]=(dp[j]&&s1[i-1]==s3[k])||(dp[j-1]&&s2[j-1]==s3[k]);
            }
        }
        return dp[m];
    }
};