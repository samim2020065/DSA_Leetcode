class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int seen_s[128]={0},seen_t[128]={0};
        int n=s.size();
        for(int i=0;i<n;i++){
        	if(seen_s[s[i]]!=seen_t[t[i]]){
        		return false;
        	}
        	seen_s[s[i]]=i+1;
        	seen_t[t[i]]=i+1;

        }
        return true;
    }
};