class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp={{'I',1},
					    {'V',5},
						{'X',10},
						{'L',50},
						{'C',100},
						{'D',500},
						{'M',1000}};
		int cnt=0;
	    for(int i=0;i<s.size();i++){
	    	if(i<(s.size()-1)){
	    		if(mp[s[i]]<mp[s[i+1]]){
	    			cnt-=mp[s[i]];
	    		}
	    		else{
	    			cnt+=mp[s[i]];
	    		}
	    	}
	    	else{
	    		cnt+=mp[s[i]];
	    	}
	    	//cout<<cnt<<endl;
	    }
	    return cnt;
    }
};