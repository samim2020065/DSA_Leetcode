class Solution {
public:
    bool rotateString(string s, string goal) {
	    if(goal.size()!=s.size()){
	    	return false;
	    }
        string concat = s+s;
        for(int i=0;i<s.size();i++){
        	int f=0;
        	for(int j=i;j<i+goal.size();j++){
        		if(concat[j]!=goal[j-i]){
        			
        			f=1;
        			break;
        		}
        	}
        	if(f==0){
        		
        		return true;
        	}
        }
        return false;
    }
};