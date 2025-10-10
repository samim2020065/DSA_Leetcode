class Solution {
public:
int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int>cnt(n+1);
        for(int i=0;i<n;i++){
            cnt[min(citations[i],n)]++;
        }
        int cum=0;
        for(int i=n;i>=0;i--){
            cum+=cnt[i];
            if(cum>=i){
                return i;
            }
        }
        return 0;
    }
};