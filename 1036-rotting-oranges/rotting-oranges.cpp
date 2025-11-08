class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0,times=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(grid[i][j]!=0){
        			cnt++;
        		}
        		if(grid[i][j]==2){
        			q.push({i,j});
        		}
        	}
        }
        vector<int>qx={1,-1,0,0};
        vector<int>qy={0,0,1,-1};
        while(!q.empty()){
        	int k=q.size();
        	cnt-=k;
        	while(k--){
        		int x=q.front().first,y=q.front().second;
        		q.pop();
        		for(int i=0;i<4;i++){
        			int cur_x=x+qx[i],cur_y=y+qy[i];
        			if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<m&&grid[cur_x][cur_y]==1){
        				grid[cur_x][cur_y]=2;
        				q.push({cur_x,cur_y});
        			}
        		}
        	}
        	if(!q.empty()){
        		times++;
        	}
        }
        return cnt==0?times:-1;
    }
};