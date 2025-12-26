class Solution {
public:
int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        queue<pair<string,int>>q;
        q.push({startGene,0});
        vector<char>genes={'A','C','G','T'};
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string curr=it.first;
            int steps=it.second;
            if(endGene==curr){
                return steps;
            }
            for(int i=0;i<curr.size();i++){
                char original=curr[i];
                for(auto g:genes){
                    if(g==original){
                        continue;
                    }
                    curr[i]=g;
                    if(st.count(curr)){
                        q.push({curr,steps+1});
                        st.erase(curr);
                    }
                }
                curr[i]=original;
            }
        }
        return -1;
    }
};