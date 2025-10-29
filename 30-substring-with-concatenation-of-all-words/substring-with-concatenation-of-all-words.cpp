class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int wordLen=words[0].size();
        int totalLen=words.size()*wordLen;
        vector<int>ans;
        if(n<totalLen){
            return ans;
        }
        unordered_map<string,int>freq,seen;
        for(auto it:words){
            freq[it]++;
        }
        for(int i=0;i<wordLen;i++){
            int left=i;
            int cnt=0;
            for(int right=i;right+wordLen<=n;right+=wordLen){
                string word=s.substr(right,wordLen);
                if(freq.find(word)!=freq.end()){
                    seen[word]++;
                    cnt++;
                    while(seen[word]>freq[word]){
                        string leftword=s.substr(left,wordLen);
                        seen[leftword]--;
                        left+=wordLen;
                        cnt--;

                    }
                    if(cnt==words.size()){
                        ans.push_back(left);
                        string leftword=s.substr(left,wordLen);
                        seen[leftword]--;
                        left+=wordLen;
                        cnt--;
                    }
                }
                else{
                    seen.clear();
                    cnt=0;
                    left=right+wordLen;
                }
            }
            seen.clear();
        }
        return ans;
    }
bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9]={false},cols[9][9]={false},boxes[9][9]={false};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    int d=(i/3)*3+(j/3);
                    if(rows[i][num]||cols[j][num]||boxes[d][num]){
                        return false;
                    }
                    rows[i][num]=cols[j][num]=boxes[d][num]=true;
                }
                
            }
        }
        return true;
    }
};