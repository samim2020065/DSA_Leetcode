class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int prev=-1,cnt=0;
        for(int i=0;i<n;i++){
            if(prev==-1){
                prev=points[i][1];
                cnt++;
            }
            else{
                if(prev>=points[i][0]){
                    prev=min(prev,points[i][1]);
                }
                else{
                    prev=points[i][1];
                    cnt++;
                }
            }
        }
        return cnt;
    }
};