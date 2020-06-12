class RandomizedSet {
    vector <int> set;
    unordered_map <int ,int > index;
    int Size=0;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(index.find(val)!=index.end())  // O(1)
            return false;
        index[val]=Size++;                // saving the index of val  O(1)
        set.push_back(val);               // O(1)
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(index.find(val)==index.end())  // O(1)
            return false;
        int idx=index[val];               // O(1)
        int last=set.back();              // O(1)
        set[idx]=last;                    // O(1)
        set.pop_back();                   // O(1)
        --Size;
        index[last]=idx;                  // O(1)
        index.erase(val);                 // O(1)
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return set[rand()%Size];          // O(1)
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
