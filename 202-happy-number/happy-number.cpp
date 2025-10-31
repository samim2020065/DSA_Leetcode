class Solution {
public:
int getNext(int n){
    int out=0;
    while(n){
        int rem=n%10;
        out+=(rem*rem);
        n=n/10;
    }
    return out;
}
bool isHappy(int n) {
       unordered_set<int>visit;
       while(visit.find(n)==visit.end()){
        visit.insert(n);
        n=getNext(n);
        if(n==1){
            return true;
        }
       }
       return false; 
    }
};