class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        int ind=-1;
        for(int i=n-1;i>=0;i--){
        	if((num[i]-'0')&1){
        		ind=i;
        		break;
        	}
        }
        if(ind==-1){
        	return "";
        }
        string t="";
        for(int i=0;i<=ind;i++){
            t+=num[i];
        }
        return t;
    }
};