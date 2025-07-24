class Solution {
public:
    string reverseWords(string s) {
	stack<string>st;
	string temp="";
	int n=s.size();
	for(int i=0;i<n;i++){
		//cout<<temp<<endl;
		if(s[i]==' '){
			if(temp!=""){
				st.push(temp);
				temp="";
			}
		}
		else{
			temp+=s[i];
		}
	}
	if(temp!=""){
		st.push(temp);
	}
	
	string ans="";
	while(st.size()!=1){
		//cout<<st.size()<<endl;
		ans+=st.top()+" ";
		st.pop();
	}
	ans+=st.top();
	return ans;
}
};