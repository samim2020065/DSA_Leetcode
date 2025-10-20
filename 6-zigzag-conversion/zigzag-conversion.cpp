class Solution {
public:
    string convert(string s, int numRows) {
       int n=s.size();
       if(numRows==1||numRows>n){
        return s;
       }
       string t;
       int cycleLen=(numRows-1)*2;
       for(int i=0;i<numRows;i++){
        
        for(int j=i;j<n;j+=cycleLen){
            t.push_back(s[j]);
            int diagIdx=j+cycleLen-(i*2);
            if(i!=0&&i!=(numRows-1)&&diagIdx<n){
                t.push_back(s[diagIdx]);

            }
        }
       }
       return t;
    }
};