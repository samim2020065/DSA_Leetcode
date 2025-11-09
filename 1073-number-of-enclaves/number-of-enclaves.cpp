class Solution {
public:
void dfs(vector<vector<int>>&grid,vector<vector<int>>&visited,int row,int col,int n,int m){
	visited[row][col]=1;
	vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    for(int i=0;i<4;i++){
    	int cur_x=row+dx[i],cur_y=col+dy[i];
    	if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<m&&grid[cur_x][cur_y]==1&&visited[cur_x][cur_y]==0){
			dfs(grid,visited,cur_x,cur_y,n,m);
        }
    }
}
int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
        	if(grid[0][i]==1&&visited[0][i]==0){
        		dfs(grid,visited,0,i,n,m);
        	}
        	if(grid[n-1][i]==1&&visited[n-1][i]==0){
        		dfs(grid,visited,n-1,i,n,m);
        	}
        }
        for(int i=0;i<n;i++){
        	if(grid[i][0]==1&&visited[i][0]==0){
        		dfs(grid,visited,i,0,n,m);
        	}
        	if(grid[i][m-1]==1&&visited[i][m-1]==0){
        		dfs(grid,visited,i,m-1,n,m);
        	}
        }
        int cnt=0;
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(grid[i][j]==1&&visited[i][j]==0){
        			cnt++;
        		}
        	}
        }
        return cnt;
    }
};