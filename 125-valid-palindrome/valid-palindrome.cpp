class Solution {
public:
    bool isPalindrome(string s) {
	    //cout<<s.size()<<endl;
        int left = 0,right = s.size()-1;
        while(left<right){
        	if(!isalnum(s[left])){
        		left++;
        	}
        	else if(!isalnum(s[right])){
        		right--;
        	}
        	else if(tolower(s[left])!=tolower(s[right])){
        		return false;
        	}
        	else{
        		left++;
        		right--;
        	}
        }
        return true;
    }
};