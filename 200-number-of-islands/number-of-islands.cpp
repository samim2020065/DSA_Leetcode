class Solution {
public:
void dfs(vector<vector<char>>&grid,vector<vector<int>>&visited,int row,int col,int n,int m){
    visited[row][col]=1;
    vector<int>dx={1,-1,0,0};
    vector<int>dy={0,0,1,-1};
    for(int i=0;i<4;i++){
        int cur_x=row+dx[i],cur_y=col+dy[i];
        if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<m&&grid[cur_x][cur_y]=='1'&&visited[cur_x][cur_y]==0){
                        dfs(grid,visited,cur_x,cur_y,n,m);
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                        if(visited[i][j]==0&&grid[i][j]=='1'){
                                dfs(grid,visited,i,j,n,m);
                                cnt++;
                        }
                }
        }
        return cnt;
    }
};