class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int i=0,c=1;
        string t;
        for(int i=1;i<n;i++){
        	if(s[i]=='('){
              c++;
        	}
        	else{
        		c--;
        	}
        	if(c!=0){
                t.push_back(s[i]);
        	}
        	else{
        		c++;
        		i++;
        	}
        }
        return t;
    }
};