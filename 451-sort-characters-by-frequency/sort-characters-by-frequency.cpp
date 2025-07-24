class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> freq(62,{0,'0'});
        for(int i=0;i<s.size();i++){
        	if(s[i]>='a'&&s[i]<='z'){
        		int pos=s[i]-'a';
        		freq[pos].first++;
        		freq[pos].second=s[i];
        	}
        	else if(s[i]>='A'&&s[i]<='Z'){
        		int pos=s[i]-'A'+26;
        		freq[pos].first++;
        		freq[pos].second=s[i];
        	}
        	else{
        		int pos=s[i]-'0'+52;
        		freq[pos].first++;
        		freq[pos].second=s[i];
        	}
        }
        sort(freq.begin(),freq.end(),[](const pair<int,char>&a,const pair<int,char>&b){
        	return a.first>b.first;
        }); 
        string t; 
        for(auto it:freq){
        	int val=it.first;
        	char c=it.second;
        	for(int i=0;i<val;i++){
        		t.push_back(c);
        	}
        }  
        return t;

    }
};