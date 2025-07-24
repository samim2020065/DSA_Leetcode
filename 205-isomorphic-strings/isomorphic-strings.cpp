class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int seen[128]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
        	char a=s[i],b=t[i];
        	if(!seen[a]){
        		for(char c:seen){
        			if(c==b){
        				return false;
        			}
        		}
        		seen[a]=b;
        	}
        	else if(seen[a]!=b){
        		return false;
        	}
        }
        return true;
    }
};