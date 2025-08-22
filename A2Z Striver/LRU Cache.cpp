class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> pages_ref;
    list<pair<int, int>> pages;
    int capacity;
public:
    LRUCache(int cap): capacity(cap) {}

    void updateRecent(int &key) {
        pages.splice(pages.begin(), pages, pages_ref[key]);
    }
    
    int get(int key) {
        if(pages_ref.count(key)) {
            updateRecent(key);
            return pages_ref[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(pages_ref.count(key)) {
            pages_ref[key]->second = value;
            cout << value <<endl;
            updateRecent(key);
            return;
        }

        if(pages_ref.size() == capacity) {
            pages_ref.erase(pages.back().first);
            pages.pop_back();
        }
        pages.push_front({key, value});
        pages_ref[key] = pages.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
