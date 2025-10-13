class Solution {
public:
    string intToRoman(int num) {
        string ans="";
        vector<pair<int,string>>val={{1000,"M"},{900,"CM"},{500,"D"},{400,"CD"},{100,"C"},{90,"XC"},{50,"L"},{40,"XL"},{10,"X"},{9,"IX"},{5,"V"},{4,"IV"},{1,"I"}};
        
        for(auto &it:val){
            while(num>=it.first){
              
                ans+=it.second;
                num-=it.first;
                
            }
            
        }
        
        return ans;

    }
};