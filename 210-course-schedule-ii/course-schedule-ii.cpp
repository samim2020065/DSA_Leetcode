class Solution {
public:
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	    vector<vector<int>>adj(numCourses);
	    vector<int>ind(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
        	int x=prerequisites[i][0];
        	int y=prerequisites[i][1];
        	adj[y].push_back(x);
        	ind[x]++;
        }
        vector<int>v;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
        	if(ind[i]==0){
        		q.push(i);
        	}
        }
        while(!q.empty()){
        	int x=q.front();
        	q.pop();
        	v.push_back(x);
        	for(auto it:adj[x]){
        		ind[it]--;
        		if(ind[it]==0){
        			q.push(it);
        		}
        	}
        }
        if(v.size()==numCourses){
        	return v;
        }
        return {};
    }
};