class Solution {
public:
bool isValid(int x,int y,vector<vector<int>>&board){
    return (x>=0&&y>=0&&x<board.size()&&y<board[0].size());
}
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int>dx={0,0,-1,1,1,1,-1,-1};
        vector<int>dy={-1,1,0,0,-1,1,-1,1};
        for(int rows=0;rows<n;rows++){
            for(int cols=0;cols<m;cols++){
                int cnt=0;
                for(int i=0;i<8;i++){
                    int cur_x=rows+dx[i];
                    int cur_y=cols+dy[i];
                    if(isValid(cur_x,cur_y,board)&&abs(board[cur_x][cur_y])==1){
                        cnt++;
                    }
                }
                if(board[rows][cols]==1&&(cnt<2||cnt>3)){
                    board[rows][cols]=-1;
                }
                if(board[rows][cols]==0&&cnt==3){
                    board[rows][cols]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]>=1){
                    board[i][j]=1;
                }
                else{
                    board[i][j]=0;
                }
            }
        }
    }
};