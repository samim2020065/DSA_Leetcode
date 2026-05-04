class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size();
        int i=0;
        vector<string>ans;
        while(i<n){
            int j=i;
            string temp="";
            int len=0;
            while(j<n&&len+words[j].size()+(j-i)<=maxWidth){
                len+=words[j].size();
                j++;
            }
            int spaces=maxWidth-len;
            int gap=j-1-i;
            if(gap==0){
                temp+=words[i]+string(maxWidth-words[i].size(),' ');
            }
            else if(j==n){
                for(int k=i;k<j;k++){
                    if(k==j-1){
                        temp+=words[k];
                    }
                    else{
                        temp+=words[k]+" ";
                    }
                }
                temp+=string(maxWidth-temp.size(),' ');
            }
            else{
                int spaceEach=spaces/gap;
                int extra=spaces%gap;
                for(int k=i;k<j;k++){
                    if(k==j-1){
                        temp+=words[k];
                    }
                    else{
                        temp+=words[k]+string(spaceEach+(extra-->0),' ');
                    }
                }
            }
            i=j;
            ans.push_back(temp);
        }
        return ans;
    }
};