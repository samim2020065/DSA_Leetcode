class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=prices[0],mx_profit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>mn){
                mx_profit=max(mx_profit,prices[i]-mn);
            }
            mn=min(mn,prices[i]);
        }
        return mx_profit;
    }
};