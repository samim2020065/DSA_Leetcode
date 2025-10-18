class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n=gas.size();
    int avail=0,total_gas=0,total_cost=0;
    for(int i=0;i<n;i++){
        total_cost+=cost[i];
        total_gas+=gas[i];
    }
    if(total_cost>total_gas){
        return -1;
    }
    int start=0;
    for(int i=0;i<n;i++){
        avail+=(gas[i]-cost[i]);
        if(avail<0){
            avail=0;
            start=i+1;
        }
    }
    return start;
}
};