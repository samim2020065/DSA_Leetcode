class Solution {
public:
double myPow(double x, int n) {
        long long exp=n;
        if(n<0){
            x=1/x;
            exp=-exp;
        }
        double ans=1.0;
        while(exp){
            if(exp&1){
                ans=ans*x;
            }
            x=x*x;
            exp>>=1;
        }
        return ans;
    }
};