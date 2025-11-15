class DSU{
public:
    vector<int>par,rank,size;
    DSU(int n){
        par.resize(n);
        rank.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
    }
    int find(int x){
        if(par[x]==x){
            return par[x];
        }
        return par[x]=find(par[x]);
    }
    void unite(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return;
        }
        if(rank[px]<rank[py]){
            par[px]=py;
        }
        else if(rank[px]>rank[py]){
            par[py]=px;
        }
        else{
            par[py]=px;
            rank[px]++;
        }
    }
    void unionbysize(int x,int y){
        int px=find(x);
        int py=find(y);
        if(px==py){
            return;
        }
        if(size[px]<size[py]){
            par[px]=py;
            size[py]+=size[px];
        }
        else{
            par[py]=px;
            size[px]+=size[py];
        }       
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DSU dsu(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0){
                    continue;
                }
        int node=row*n+col;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        for(int i=0;i<4;i++){
            int cur_x=row+dx[i],cur_y=col+dy[i];
            int adjNode=cur_x*n+cur_y;
            if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<n&&grid[cur_x][cur_y]==1){
                            dsu.unionbysize(node,adjNode);
            }
        }
       }
      }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1){
                    continue;
                }
                set<int>st;
                int node=row*n+col;
                vector<int>dx={1,-1,0,0};
                vector<int>dy={0,0,1,-1};
                for(int i=0;i<4;i++){
                    int cur_x=row+dx[i],cur_y=col+dy[i];
                    int adjNode=cur_x*n+cur_y;
                    if(cur_x>=0&&cur_y>=0&&cur_x<n&&cur_y<n&&grid[cur_x][cur_y]==1){
                                    st.insert(dsu.find(adjNode));
                    }
                }
                int sz=0;
                for(auto it:st){
                    sz+=dsu.size[it];
                }
                mx=max(mx,sz+1);
            }
        }
        for(int i=0;i<n*n;i++){
            mx=max(mx,dsu.size[dsu.find(i)]);
        }
        return mx;     
    }
};