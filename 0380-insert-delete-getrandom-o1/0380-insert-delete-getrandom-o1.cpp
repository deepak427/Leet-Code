class RandomizedSet {
public:
    unordered_set<int> randomizedSet;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(randomizedSet.find(val)!=randomizedSet.end()) return false;
        randomizedSet.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(randomizedSet.find(val)==randomizedSet.end()) return false;
        randomizedSet.erase(val);
        return true;
    }
    
    int getRandom() {
        int minVal = 0;
        int maxVal = randomizedSet.size()-1;
        int randomNumberInRange = minVal + (rand() % (maxVal - minVal + 1));
        
        auto it = randomizedSet.begin();
        for(int i = 0; i < randomNumberInRange; ++i){
            ++it;
        }

        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */