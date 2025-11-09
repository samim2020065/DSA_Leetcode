class Solution {
public:
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>dist(n,vector<int>(m,0));
        vector<vector<int>>visited(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(mat[i][j]==0){
        			q.push({{i,j},0});
        			visited[i][j]=1;
        		}
        	}
        }
        while(!q.empty()){
        	int x=q.front().first.first;
        	int y=q.front().first.second;
        	int states=q.front().second;
        	q.pop();
        	dist[x][y]=states;
        	for(int i=0;i<4;i++){
        		int cur_x=x+dx[i],cur_y=y+dy[i];
        		if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<m&&visited[cur_x][cur_y]==0){
        			visited[cur_x][cur_y]=1;
        			q.push({{cur_x,cur_y},states+1});
        		}
        	}
        }
        return dist;
    }
};