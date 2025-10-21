class RandomizedSet {
public:
vector<int>nums;
unordered_map<int,int>idx;
RandomizedSet() {
        
    }
    
bool insert(int val) {
        if(idx.find(val)!=idx.end()){
            return false;
        }
        nums.push_back(val);
        idx[val]=nums.size()-1;
        return true;
    }
    
bool remove(int val) {
        if(idx.find(val)==idx.end()){
            return false;
        }
        int last=nums.back();
        idx[last]=idx[val];
        nums[idx[val]]=last;
        nums.pop_back();
        idx.erase(val);
        return true;
    }
    
int getRandom() {
       int ranidx=rand()%nums.size();
       return nums[ranidx]; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */