class Solution {
public:
    int myAtoi(string s) {

       int i=0;
       while(i<s.size()){
       	if(s[i]==' '){
       		i++;
       	}
       	else{
       		break;
       	}
       }

       long ans=0;
       int sign =1;
       if(i==s.size()){
       	return ans;
       }
       if(s[i]=='-'){
       	sign=-1;
       } 
       if(s[i]=='-'||s[i]=='+'){
       	i++;
       }
       int min=-2147483648,max=2147483647;
       while(i<s.size()){
       	if(s[i]>='0'&&s[i]<='9'){
       		ans=ans*10+(s[i]-'0');
       	}
       	else{
       		break;
       	}
       	i++;
       	if(sign==-1&&(-1*ans<min)){
       		return min;
       	}
       	if(sign==1&&ans>max){
       		return max;
       	}
       }
       return (int)(sign*ans);
    }
};