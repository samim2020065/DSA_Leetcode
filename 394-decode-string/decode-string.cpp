class Solution {
public:
    string decodeString(string s) {
        stack<int>intSt;
        stack<string>stringSt;
        int num=0;
        string curr="";
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='['){
                intSt.push(num);
                stringSt.push(curr);
                num=0;
                curr="";
            }
            else if(s[i]==']'){
                int len=intSt.top();
                intSt.pop();
                string prev=stringSt.top();
                stringSt.pop();
                string temp="";
                for(int i=1;i<=len;i++){
                    temp+=curr;
                }
                curr=prev+temp;
            }
            else{
                curr+=s[i];
            }
        }
        return curr;
    }
};