class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>mp={{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]>0){
                st.push(mp[s[i]]);
            }
            else{
                if(st.empty()||st.top()+mp[s[i]]!=0){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};