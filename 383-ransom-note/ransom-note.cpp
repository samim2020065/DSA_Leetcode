class Solution {
public:
bool canConstruct(string ransomNote, string magazine) {
        vector<int>freq(26,0);
        for(auto it:magazine){
            freq[it-'a']++;
        }
        for(auto it:ransomNote){
            freq[it-'a']--;
            if(freq[it-'a']<0){
                return false;
            }
        }
        return true;
    }
};