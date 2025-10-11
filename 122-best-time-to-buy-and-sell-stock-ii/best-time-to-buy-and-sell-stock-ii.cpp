class Solution {
public:
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx_profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>prices[i-1]){
                mx_profit+=prices[i]-prices[i-1];
            }
        }
        return mx_profit;
    }
};