class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int cur=words[0].size()+1;
        vector<string>ans;
        int pos=0;
        int cur_len=words[0].size();
        for(int i=1;i<words.size();i++){

            if(cur+words[i].size()>maxWidth){
                string line="";
                
                
                if((i-pos-1)==0){
                    line+=words[pos];
                    for(int m=words[pos].size()+1;m<=maxWidth;m++){
                        line+=" ";
                    }
                }
                else{
                    
                    int div=(maxWidth-cur_len)/(i-pos-1);
                    int rem=(maxWidth-cur_len)%(i-pos-1);
                    //cout<<pos<<" "<<div<<" "<<rem<<endl;
                    for(int k=pos;k<i;k++){
                        line+=words[k];
                        if(k!=(i-1)){
                            //cout<<rem<<endl;
                            if(rem>0){
                                for(int l=0;l<=div;l++){
                                    line+=" ";   
                                }
                                rem--;
                            }
                            else{
                                for(int l=0;l<div;l++){
                                    line+=" ";
                                }
                            }
                        }
                    }
                }
                ans.push_back(line);
                cur=words[i].size()+1;
                pos=i;
                cur_len=words[i].size();
            }
            else{
                cur+=words[i].size()+1;
                cur_len+=words[i].size();
            }
            // cout<<cur_len<<endl;

        }
        //cout<<pos<<endl;
        string last=words[pos];
        for(int i=pos+1;i<words.size();i++){
            last+=" "+words[i];
        }
        for(int i=last.size()+1;i<=maxWidth;i++){
            last+=" ";
        }
        ans.push_back(last);
        return ans;
    }
};