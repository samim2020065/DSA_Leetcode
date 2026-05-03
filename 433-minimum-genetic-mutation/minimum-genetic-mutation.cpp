class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        vector<char>choices={'A','C','G','T'};
        queue<pair<string,int>>q;
        q.push({startGene,0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            string curr=it.first;
            int steps=it.second;
            if(curr==endGene){
                return steps;
            }
            for(int i=0;i<curr.size();i++){
                char original=curr[i];
                for(auto it:choices){
                    curr[i]=it;
                    if(it==original){
                        continue;
                    }
                    if(st.find(curr)!=st.end()){
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