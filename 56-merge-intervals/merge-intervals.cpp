class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int first=intervals[0][0];
        int second = intervals[0][1];
        vector<int>temp={first,second};
        vector<vector<int>>ans;
        ans.push_back(temp);

        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>ans.back()[1]){
                ans.push_back({intervals[i][0],intervals[i][1]});
            }
            else{
                ans.back()[1]=max(ans.back()[1],intervals[i][1]);
            }
        }
        return ans;
    }
};