class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen=words[0].size();
        int total_words=words.size();
        int totalLen=wordLen*total_words;
        int n=s.size();
        vector<int>ans;
        unordered_map<string,int>freq;
        for(auto it:words){
            freq[it]++;
        }
        for(int i=0;i<wordLen;i++){
            unordered_map<string,int>window;
            int left=i,cnt=0;
            for(int j=i;j+wordLen<=n;j+=wordLen){
                string temp=s.substr(j,wordLen);
                if(freq.count(temp)){
                    window[temp]++;
                    cnt++;
                    while(window[temp]>freq[temp]){
                        string leftWord=s.substr(left,wordLen);
                        left+=wordLen;
                        window[leftWord]--;
                        cnt--;
                    }
                    if(cnt==total_words){
                        ans.push_back(left);
                    }
                }
                else{
                    window.clear();
                    cnt=0;
                    left=j+wordLen;
                }
            }
        }
        return ans;
    }
};