class Solution {
public:
    bool isValid(int x,int y,vector<vector<char>>&board){
        int n=board.size(),m=board[0].size();
        return x>=0&&y>=0&&x<n&&y<m;
    }
    void dfs(int x,int y,vector<vector<int>>& visited,vector<vector<char>>& board){
        visited[x][y]=1;
        vector<int>dx={0,0,-1,1};
        vector<int>dy={-1,1,0,0};
        for(int i=0;i<4;i++){
            int curr_x=x+dx[i];
            int curr_y=y+dy[i];
            if(isValid(curr_x,curr_y,board)&&!visited[curr_x][curr_y]&&board[curr_x][curr_y]=='O'){
                dfs(curr_x,curr_y,visited,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
       int n=board.size(),m=board[0].size();
       vector<vector<int>>visited(n,vector<int>(m,0)); 
       for(int i=0;i<n;i++){
        if(!visited[i][0]&&board[i][0]=='O'){
            dfs(i,0,visited,board);
        }
        if(!visited[i][m-1]&&board[i][m-1]=='O'){
            dfs(i,m-1,visited,board);
        }
       }
       for(int i=0;i<m;i++){
        if(!visited[0][i]&&board[0][i]=='O'){
            dfs(0,i,visited,board);
        }
        if(!visited[n-1][i]&&board[n-1][i]=='O'){
            dfs(n-1,i,visited,board);
        }
       }
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='O'&&!visited[i][j]){
                board[i][j]='X';
            }
        }
       }
    }
};