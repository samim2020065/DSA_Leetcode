class Solution {
public:
int mySqrt(int x) {
        long long int i=0,ans;
        while(i*i<=x*1LL){
            ans=i;
            i++;
        }
        return ans;
    }
};