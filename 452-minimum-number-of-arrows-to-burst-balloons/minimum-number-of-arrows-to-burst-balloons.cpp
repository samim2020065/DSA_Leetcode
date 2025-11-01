class Solution {
public:
int findMinArrowShots(vector<vector<int>>& points) {
       sort(points.begin(),points.end());
       int n=points.size();
       int cnt=1;
       int start=points[0][1];
       for(int i=1;i<n;i++){
        if(points[i][0]>start){
            start=points[i][1];
            cnt++;
        }
        else{
            start=min(start,points[i][1]);
        }
       }
       return cnt;
    }
};