class Solution {
public:
int reverseBits(int n) {
        string bin="";
        while(n){
        	if(n&1){
        		bin+='1';
        	}
        	else{
        		bin+='0';
        	}
        	n/=2;
        }
        for(int k=bin.size();k<32;k++){
        	bin+='0';
        }
        int result=0;
        long long base=1;
        for(int k=31;k>=0;k--){
        	result+=(bin[k]-'0')*base;
        	base*=2LL;
        }
        return result;
    }
};