class Solution {
public:
bool isValid(string s) {
    stack<int>st;
    map<char,int>mp={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
    for(int i=0;i<s.size();i++){
        if(mp[s[i]]>0){
            st.push(mp[s[i]]);
        }
        else{
            if(st.empty()){
                return false;
            }
            int t=st.top();
            st.pop();
            if((mp[s[i]]+t)!=0){
                return false;
            }
        }
    }
    if(!st.empty()){
        return false;
    }
    return true;
}
};