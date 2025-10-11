class Solution {
public:
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mx_profit=0,cur_profit=0;
        int cur=prices[0];
        for(int i=1;i<n;i++){
            if(prices[i]>cur){
                if((prices[i]-cur)>cur_profit){
                    cur_profit=prices[i]-cur;
                    
                }
                else{
                    cur=prices[i];
                    mx_profit+=cur_profit;
                    cur_profit=0;
                }
                
            }
            else{
                if(cur_profit!=0){
                    mx_profit+=cur_profit;
                    cur_profit=0;
                }
                cur=min(cur,prices[i]);
            }
            //cout<<mx_profit<<" "<<cur_profit<<" "<<cur<<endl;
        }
        mx_profit+=cur_profit;
        return mx_profit;
    }
};