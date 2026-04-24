class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        stack<pair<long long int,int>>st;
        long long int result=0;
        int sign=1;
        int i=0;
        while(i<n){
            if(isdigit(s[i])){
                long long int num=0;
                while(i<n&&isdigit(s[i])){
                    num=num*10+(s[i]-'0');
                    i++;
                }
                result=result+(sign*num);
                continue;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push({result,sign});
                result=0,sign=1;
            }
            else if(s[i]==')'){
                auto it=st.top();
                st.pop();
                result=it.first+(result*it.second);
            }
            i++;
        }
        return result;
    }
};