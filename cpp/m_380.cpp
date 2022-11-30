// You must implement the functions of the class such that each function works in average O(1) time complexity.
class RandomizedSet {
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if (umap.find(val) != umap.end()) {
            return false;
        }
        vec.push_back(val);
        umap[val] = vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (umap.find(val) != umap.end()) {
            umap[vec.back()] = umap[val];
            vec[umap[val]] = vec.back();
            vec.pop_back();
            umap.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
    unordered_map<int, int> umap;
    vector<int> vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
