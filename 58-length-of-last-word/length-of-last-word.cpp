class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx=0,c=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]!=' '){
                idx=i;
                break;
            }
        }
        for(int i=idx;i>=0;i--){
            if(s[i]==' '){
                break;
            }
            else{
                c++;
            }
        }
        return c;
    }
};