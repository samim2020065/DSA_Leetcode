class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string first = strs[0];
        string last = strs[strs.size()-1];
        string t="";
        for(int i=0;i<first.size();i++){
        	if(first[i]==last[i]){
        		t+=first[i];
        	}
        	else{
        		break;
        	}
        }
        return t;
    }
};