class Solution {
public:
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int oldColor=image[sr][sc];
        if(oldColor==color){
        	return image;
        }
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        queue<pair<int,int>>q;
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
        	int x=q.front().first,y=q.front().second;
        	q.pop();
        	for(int i=0;i<4;i++){
        		int cur_x=x+dx[i],cur_y=y+dy[i];
        		if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<m&&image[cur_x][cur_y]==oldColor){
        			q.push({cur_x,cur_y});
        			image[cur_x][cur_y]=color;
        		}
        	}
        }
        return image;
    }
};