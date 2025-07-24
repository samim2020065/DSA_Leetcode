class Solution {
public:
    string reverseWords(string s) {
	string temp="",ans="";
	int n=s.size();
	for(int i=0;i<n;i++){
		//cout<<temp<<endl;
		if(s[i]==' '){
			if(temp!=""){
				if(ans!=""){
				ans=temp+" "+ans;
				temp="";
			}
			else{
				ans=temp;
				temp="";
			}
		  }
			
		}
		else{
			temp+=s[i];
		}
	}
	if(temp!=""){
		if(ans!="")
		  ans=temp+" "+ans;
		else
		  ans=temp;
	}
	return ans;
}
};